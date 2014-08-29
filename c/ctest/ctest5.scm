;; bootstrap shim

(define (make-cell v)
  (cons 'cell v))

(define (set-cell! cell value)
  (set-cdr! cell value))

(define (cell-value cell)
  (cdr cell))

(define (collector)
  (let ((list (make-cell '()))
        (last (make-cell '())))
    (cons (lambda ()
            (cell-value list))
          (lambda (value)
            (if (null? (cell-value last))
                (begin
                  (set-cell! list (cons value '()))
                  (set-cell! last (cell-value list)))
                (begin
                  (set-cdr! (cell-value last) (cons value '()))
                  (set-cell! last (cdr (cell-value last)))))))))

(define (all p l)
  (if (null? l)
      #t
      (if (p (car l))
          (all p (cdr l))
          #f)))

(define (any p l)
  (if (null? l)
      #f
      (if (p (car l))
          #t
          (any p (cdr l)))))

(define (fold kons knil klist)
  (if (null? klist)
      knil
      (kons (car klist)
            (fold kons knil (cdr klist)))))

(define (list-index* i elt list)
  (if (null? list)
      #f
      (if (equal? elt (car list))
          i
          (list-index* (+ i 1) elt (cdr list)))))
(define (list-index elt list)
  (list-index* 0 elt list))

(define (assoc k l)
  (if (null? l)
      #f
      (if (equal? k (caar l))
          (car l)
          (assoc k (cdr l)))))


(define (mangle s)
  (let ((down (lambda (khar)
                (cond 
                 ((equal? khar #\-) (list #\_))
                 ((equal? khar #\?) (list #\_ #\q #\u #\e #\s #\t #\i #\o #\n))
                 ((equal? khar #\!) (list #\_ #\b #\a #\n #\g))
                 ((equal? khar #\=) (list #\_ #\n #\u #\m #\e #\q))
                 ((equal? khar #\<) (list #\_ #\l #\t))
                 ((equal? khar #\>) (list #\_ #\g #\t))
                 ((equal? khar #\*) (list #\_ #\s #\t #\a #\r))
                 (else (list khar))))))
    (let ((mangled (map down (string->list (symbol->string s)))))
      (list->string (foldl append '() mangled)))))

(define (mangle* s n)
  (let ((m (mangle s)))
    (cond ((or (equal? s 'invoke-closure)
               (equal? s 'vector))
           (string-append "scm_" (string-append m (number->string n))))
          ((or (equal? s 'make-closure)
               (equal? s 'vector-ref))
           (string-append "scm_" m))
          (else m))))
(define (concat-map f l)
  (if (null? l)
      '()
      (append (f (car l))
              (concat-map f (cdr l)))))

(define (escape-string s)
  (let ((escape-char (lambda (c)
                       (if (eq? c #\")
                           (list #\\ #\")
                           (list c)))))
    (list->string (concat-map escape-char (string->list s)))))

(define (string-quote s)
  (string-append "\"" (string-append (escape-string s) "\"")))

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
           (cond ((= n 0) #f)
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
    (error "__error" "scm_error")
    (newline "__newline" "scm_newline")
    (put-string "__put_string" "scm_put_string")
    (string-append "__string_append" "scm_string_append")

    (number->string "__number_to_string" "scm_number_to_string")
    (char->string "__char_to_string" "scm_char_to_string")
    (symbol->string "__symbol_to_string" "scm_symbol_to_string")

    (string->char "__string_to_char" "scm_string_to_char")
    (string->symbol "__string_to_symbol" "scm_string_to_symbol")
    (string->number "__string_to_number" "scm_string_to_number")
    (string->list "__string_to_list" "scm_string_to_list")
    
    (cons "__cons" "scm_cons")
    (car "__car" "scm_car")
    (cdr "__cdr" "scm_cdr")
    (set-car! "__set_car" "scm_set_car")
    (set-cdr! "__set_cdr" "scm_set_cdr")
    
    (boolean "__boolean" "scm_boolean")
    (eq? "__eq_question" "scm_eq_question")
    (number? "__number_question" "scm_number_question")
    (boolean? "__boolean_question" "scm_boolean_question")
    (char? "__char_question" "scm_char_question")
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
    ))

(define (prim? exp)
  (any (lambda (prim)
         (eq? exp (car prim)))
       (primitives)))

(define (rename-prim p)
  (let ((a (assoc p (primitives))))
    (if a
        (cadr a)
        (error (string-append "unhandled primitive: " (tostring p))))))

(define (rename-prim-code p)
  (let ((a (assoc p (primitives))))
    (if a
        (caddr a)
        (error (string-append "unhandled primitive: " (tostring p))))))

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
      (boolean? form)
      (string? form)))

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
        ((char? term)
         (display "scm_char")
         (display "(")
         (display (string-quote (char->string term)))
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
                        (error (string-append "Dont know how to quote that: " (tostring term)))))))
        ((and (list? term)
              (not (null? term)))
         (emit-call (car term) (cdr term)))
        (else (error (string-append (tostring term) "emit-c!")))))
  ;;(display (emit-c 3)) (newline)
  ;;(display (emit-c '(f x))) (newline)
  ;;(display (emit-c '(lambda (x) (x x x)))) (newline)
  


(define (compile-c-definitions program)
  (let ((declarations (collector))
        (definitions (make-cell '()))
        (defined-values (collector))
        (sets (collector)))
    (for-each (lambda (definition)
                ;;(newline)
                ;;(pretty-print definition)
                ;;(newline)
                ;; (define name (lambda (args) code))
                (cond ((and (= (length definition) 3)
                             (equal? 'define (car definition))
                             (list? (caddr definition))
                             (equal? 'lambda (car (caddr definition))))
                       (let ((name (cadr definition))
                             (body (caddr definition)))
                         (let ((collector (collector)))
                           (let* ((cc (perform-closure-conversion body))
                                  (main ((hoist (cdr collector)) cc))
                                  (new-definitions ((car collector))))
                             (set-cell! definitions (append
                                                     (cell-value definitions)
                                                     (append new-definitions
                                                             (list `(define ,name ,main)))))))))
                      ((and (= (length definition) 3)
                            (equal? 'define (car definition)))
                       
                       (let ((name (cadr definition))
                             (body (caddr definition)))
                         (let ((collector (collector)))
                           (let* ((cc (perform-closure-conversion body))
                                  (main ((hoist (cdr collector)) cc))
                                  (new-definitions ((car collector))))
                             ((cdr defined-values) (cons (mangle (cadr definition))
                                                         main))
                             (set-cell! definitions (append (cell-value definitions) new-definitions)))))

                       )
                      (else (error "BAD DEFINE"))))
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
              (cell-value definitions))
    (emit-prim-prelude-prelude)
    (for-each (lambda (decl)
                (display "scm* ")
                (display decl)
                (display ";")
                (newline))
              (append ((car declarations))
                      (map car ((car defined-values)))))
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
                (cell-value definitions))
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
                  (display " = ")
                  (emit-c (cdr name-set))
                  (display ";")
                  (newline))
                ((car defined-values)))
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


(define (hoist x) x)
(define (perform-closure-conversion x) x)

(define (moo)
  (display (mangle 'foobar)) (newline)
  (display (mangle 'foobar->baz)) (newline)
  (display (mangle '=)) (newline)
  (display (mangle 'null?)) (newline)
  
  (display (mangle* 'foobar)) (newline)
  (display (mangle* 'foobar->baz)) (newline)
  (display (mangle* '=)) (newline)
  (display (mangle* 'null?)) (newline)
  
  (display (prim? 'foo)) (newline)
  (display (prim? '=)) (newline)
  (display (prim? 'null?)) (newline)
  
  (display (rename-prim 'null?)) (newline)

  (emit-c 'null?) (newline)

  )
