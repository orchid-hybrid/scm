(define (mangle s)
  (let ((down (lambda (char)
                (cond 
                 ((equal? char #\-) (list #\_))
                 ((equal? char #\?) (list #\_ #\q #\u #\e #\s #\t #\i #\o #\n))
                 ((equal? char #\!) (list #\_ #\b #\a #\n #\g))
                 ((equal? char #\=) (list #\_ #\n #\u #\m #\e #\q))
                 ((equal? char #\<) (list #\_ #\l #\t))
                 ((equal? char #\>) (list #\_ #\g #\t))
                 (else (list char))))))
    (let ((mangled (map down (string->list (symbol->string s)))))
      (list->string (apply append mangled)))))

(define (mangle* s n)
  (let ((m (mangle s)))
    (cond ((or (equal? s 'invoke-closure)
               (equal? s 'vector))
           (string-append "scm_" (string-append m (number->string n))))
          ((or (equal? s 'make-closure)
               (equal? s 'vector-ref))
           (string-append "scm_" m))
          (else m))))

(define (string-quote s)
  (string-append "\"" (string-append s "\"")))

(define (emit-call f args)
  (cond ((and (equal? f 'vector-ref)
              (= 2 (length args))
              (equal? (car args) 'env))
         (display "env[")
         (display (cadr args))
         (display "]"))
        (else
         (display (mangle* f (length args)))
         (display "(")
         (let ((n (length args)))
           (cond ((= n 0))
                 ((> n 0)
                  (if (equal? f 'vector)
                      (display "")
                      1)
                  (emit-c (car args))
                  (for-each (lambda (arg)
                              (display ",")
                              (if (equal? f 'vector)
                                  (display "")
                                  1)
                              (emit-c arg))
                            (cdr args)))))
         (display ")"))))

(define (primitives)
  '((print "__print" "scm_print")
    (newline "__newline" "scm_newline")
    
    (cons "__cons" "scm_cons")
    (car "__car" "scm_car")
    (cdr "__cdr" "scm_cdr")
    (set-car! "__set_car" "scm_set_car")
    (set-cdr! "__set_cdr" "scm_set_cdr")
    
    (boolean "__boolean" "scm_boolean")
    (eq? "__eq_question" "scm_eq_question")
    (number? "__number_question" "scm_number_question")
    (boolean? "__boolean_question" "scm_boolean_question")
    (string? "__string_question" "scm_string_question")
    (symbol? "__symbol_question" "scm_symbol_question")
    (vector? "__vector_question" "scm_vector_question")
    (null? "__null_question" "scm_null_question")
    (pair? "__pair_question" "scm_pair_question")
    (procedure? "__procedure_question" "scm_procedure_question")

    (+ "__add" "scm_add")
    (- "__sub" "scm_sub")
    (* "__mul" "scm_mul")
    (/ "__div" "scm_div")
    (= "__num_eq" "scm_num_eq")
    (<  "__num_lt"  "scm_num_lt")
    (<= "__num_lte" "scm_num_lte")
    (>  "__num_gt"  "scm_num_gt")
    (>= "__num_gte" "scm_num_gte")
    (number->string "__num_to_string" "scm_num_to_string")
    ))

(define (prim? exp)
  (any (lambda (prim)
         (eq? exp (car prim)))
       (primitives)))

(define (rename-prim p)
  (cond
   ((assoc p (primitives)) => cadr)
   (else             (error "unhandled primitive: " p))))

(define (emit-prim-prelude-prelude)
  (for-each
   (lambda (c)
     (display "scm* ")
     (display (cadr c))
     (display ";")
     (newline))
   (primitives)))

(define (emit-prim-prelude)
  (for-each
   (lambda (c)
     (display (cadr c))
     (display " = scm_wrap_prim(")
     (display (caddr c))
     (display ");")
     (newline))
   (primitives)))

(define (self-evaluating-form? form)
  (or (null? form)
      (number? form)
      (boolean? form)))

(define (emit-c term)
  (cond ((prim? term)
	 (display (rename-prim term)))
        ((null? term)
         (display "scmalloc((scm){ .t = scm_type_null })"))
	((number? term)
         (display (string-append "scmalloc((scm){ .t = scm_type_number, .v.n = "
                                 (string-append (number->string term) " })"))))
	((boolean? term)
         (display (if term
		      "scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 })"
		      "scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 })")))
	 ((string? term)
         (display "scm_string")
         (display "(")
         (display (string-quote term))
         (display ")"))
        ((symbol? term)
         (display (mangle term)))
        ((and (list? term)
              (not (null? term))
              (= (length term) 2)
              (equal? (car term) 'quote))
         (if (symbol? (cadr term))
             (begin (display "scm_make_symbol(")
                    (display (string-quote (symbol->string (cadr term))))
                    (display ")"))
             (if (self-evaluating-form? (cadr term))
                 (emit-c (cadr term))
                 (begin (display term)
                        (newline)
                        (error (list "Dont know how to quote that: " term))))))
        ((and (list? term)
              (not (null? term)))
         (emit-call (car term) (cdr term)))
        (else (error term "emit-c!"))))

(define (test-c term)
  (let ((collector (make-collector)))
    (let* ((cc (perform-closure-conversion term))
           (main ((hoist (cdr collector)) cc))
           (definitions ((car collector))))
      (display "#include \"scm.h\"")
      (newline)
      (emit-prim-prelude-prelude)
      (newline)
      (newline)
      (for-each (lambda (definition)
                  ;;(define name (lambda (args) body))
                  (let ((name (cadr definition))
                        (args (cadr (caddr definition)))
                        (body (caddr (caddr definition))))
                    (display "scm ")
                    (display (mangle name))
                    (display "(")
                    (display "scm** env")
                    (for-each (lambda (arg)
                                (display ", ")
                                (display "scm ")
                                (display (mangle arg)))
                              (cdr args))
                    (display ") {")
                    (newline)
                    (display "  return ")
                    (emit-c body)
                    (display ";")
                    (newline)
                    (display "}")
                    (newline)
                    (newline)))
                definitions)
      (display "void main() {")
      (newline)
      (emit-prim-prelude)
      (newline)
      (display "  ")
      (emit-c main)
      (display ";")
      (newline)
      (display "}")
      (newline))))

(define (compile-c-definitions program)
  (let ((declarations (make-collector))
        (definitions '())
        (sets (make-collector)))
    (for-each (lambda (definition)
                ;;(newline)
                ;;(pretty-print definition)
                ;;(newline)
                ;; (define name (lambda (args) code))
                (if (and (= (length definition) 3)
                         (equal? 'define (car definition))
                         (list? (caddr definition))
                         (equal? 'lambda (car (caddr definition))))
                    (let ((name (cadr definition))
                          (body (caddr definition)))
                      (let ((collector (make-collector)))
                        (let* ((cc (perform-closure-conversion body))
                               (main ((hoist (cdr collector)) cc))
                               (new-definitions ((car collector))))
                          (set! definitions (append definitions (append new-definitions (list `(define ,name ,main))))))))
                    (error "BAD DEFINE")))
              program)
   
    (display "#include \"scm.h\"")
    (newline)
    (newline)
    (for-each (lambda (definition)
                (if (equal? 'lambda (car (caddr definition)))
                    ;;(define name (lambda (args) body))
                    #t
                    (begin
                      ;; (define value make-closure ...
                      ((cdr declarations) (mangle (cadr definition)))
                      ((cdr sets) (cons (mangle (cadr definition))
                                        (caddr definition)))
                      )))
              definitions)
    (emit-prim-prelude-prelude)
    (for-each (lambda (decl)
                (display "scm* ")
                (display decl)
                (display ";")
                (newline))
              ((car declarations)))
    (newline)
    (newline)
    (for-each (lambda (definition)
                ;;(display "DEFINITION")(newline)
                ;;(display definition)(newline)(newline)
                (if (equal? 'lambda (car (caddr definition)))
                    ;;(define name (lambda (args) body))
                    (let ((name (cadr definition))
                          (args (cadr (caddr definition)))
                          (body (caddr (caddr definition))))
                      (display "scm* ")
                      (display (mangle name))
                      (display "(")
                      (display "scm** env")
                      (for-each (lambda (arg)
                                  (display ", ")
                                  (display "scm* ")
                                  (display (mangle arg)))
                                (cdr args))
                      (display ") {")
                      (newline)
                      (display "  return ")
                      ;;(display "DEFINITION")(newline)
                      ;;(pretty-print definition)(newline)
                      ;;(display "BODY")(newline)
                      ;;(pretty-print body)(newline)
                      (newline)
                      (emit-c body)
                      (display ";")
                      (newline)
                      (display "}")
                      (newline)
                      (newline))
                    ;; (define value make-closure ...
                    (begin
                      (if (equal? 'make-closure (car (caddr definition)))
                          #f
                          (error "NO"))
                      
                      
                      )))
                definitions)
      (display "void main() {")
      (newline)
      (emit-prim-prelude)
      (for-each (lambda (name-set)
                  (display (car name-set))
                  (display " = ")
                  (emit-c (cdr name-set))
                  (display ";")
                  (newline))
                ((car sets)))
      (newline)
      (for-each (lambda (name-set)
                  (display (car name-set))
                  (display "->v.cons.cdr = ")
                  (emit-c (caddr (cdr name-set))) ;; DANGEROUS ASUMPTINS THAT CADDR IS scm_vector
                  (display ";")
                  (newline))
                ((car sets)))
      (newline)
      (display "  ")
      (display "scm_invoke_closure1(moo);")
      ;;(emit-c main)
      ;;(display ";")
      (newline)
      (display "}")
      (newline)))
