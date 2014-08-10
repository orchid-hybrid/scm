;; term ::= var
;;        | number | (quote term)
;;        | (lambda (var ...) term)
;;        | (set! var term)
;;        | (term ...)

(define (term-var? term)
  (symbol? term))

(define (term-quote? e)
  (and (list? e)
       (= (length e) 2)
       (equal? 'quote (car e))))

(define (term-lambda? e)
  (and (list? e)
       (>= (length e) 3)
       (equal? (car e) 'lambda)
       (list? (cadr e))
       ;; all symbols cadr
       ))

(define (term-set!? e)
  (and (list? e)
       (= (length e) 3)
       (equal? (car e) 'set!)
       ))

(define (term-application? term)
  (list? term))

(define (set-remove-element set element)
  (if (null? set)
      set
      (if (equal? (car set) element)
          (set-remove-element (cdr set) element)
          (cons (car set) (set-remove-element (cdr set) element)))))
(define (set-remove set list)
  (if (null? list)
      set
      (set-remove (set-remove-element set (car list)) (cdr list))))

(define (set-intersect set-1 set-2)
  (if (null? set-1)
      set-1
      (if (member (car set-1) set-2)
          (cons (car set-1) (set-intersect (cdr set-1) set-2))
          (set-intersect (cdr set-1) set-2))))

(define (set-union set-1 set-2)
  (define (filter set-2)
    (if (null? set-2)
        set-2
        (if (member (car set-2) set-1)
            (filter (cdr set-2))
            (cons (car set-2) (filter (cdr set-2))))))
  (append set-1 (filter set-2)))
(define (set-union* sets)
  (if (null? sets)
      sets
      (set-union (car sets) (set-union* (cdr sets)))))

(define (lambda-lift-annotate term)
  ;; This annotates lambda terms with the list of variables
  ;; that they use.
  ;;
  ;; a-term ::= var
  ;;          | (quote term)
  ;;          | (lambda ((var ...) . free-vars) a-term)
  ;;          | (set! var a-term)
  ;;          | (a-term ...)
  ;;
  ;; it returns a pair: a-term and list of free variables
  ;; to make the recursion work
  ;;
  (cond ((term-var? term)
         (cons term (list term)))
        ((or (number? term)
             (term-quote? term))
         (cons term '()))
        ((term-lambda? term)
         (let* ((binders (cadr term))
                (body (caddr term))
                (result (lambda-lift-annotate body))
                (a-body (car result))
                (a-body-free-vars (cdr result))
                (free-vars (set-remove a-body-free-vars binders)))
           (cons `(lambda (,binders . ,free-vars) ,a-body)
                 free-vars)))
        ((term-set!? term)
         (let* ((var (cadr term))
                (result (lambda-lift-annotate (caddr term)))
                (a-term (car result))
                (free-vars (cdr result)))
           (cons `(set! ,var ,a-term)
                 free-vars)))
        ((term-application? term)
         (let* ((results (map lambda-lift-annotate term))
                (a-terms (map car results))
                (free-vars (set-union* (map cdr results))))
           (cons a-terms free-vars)))
        (else (error "I don't know what this is: " term))))

(define lambda-lift
  (lambda (local-scope)
    (lambda (term)
      ;; This traverses the annotated term both removing all
      ;; annotations and also adding parameters to lambda calls
      ;; of the form
      ;;
      ;; ((lambda (var ...) body ...) param ...)
      ;;
      ;; reducing the number of free variables that they close
      ;; over. This is an optimization so we can stack allocate
      ;; them, saving heap.
      (cond ((term-var? term)
             term)
            ((or (number? term)
                 (term-quote? term))
             term)
            ((term-lambda? term)
             (let* ((binders (caadr term))
                    (free-vars (cdadr term))
                    (body (caddr term)))
               `(lambda ,binders ,((lambda-lift (set-union binders local-scope)) body))))
            ((term-set!? term)
             (let ((var (cadr term))
                   (a-term (caddr term)))
               `(set! ,var ,(lambda-lift a-term))))
            ((term-application? term)
             (if (and (not (null? term))
                      (term-lambda? (car term)))
                 (let* ((a-lambda-term (car term))
                        (binders (caadr a-lambda-term))
                        (free-vars (cdadr a-lambda-term))
                        (a-body (caddr a-lambda-term))
                        (extension (set-intersect local-scope free-vars)))
                   ;;(print `(debugging ,a-lambda-term - binders ,binders - free-vars ,free-vars - local-scope ,local-scope - extension ,extension))
                   `((lambda ,(append binders extension)
                       ,((lambda-lift (set-union binders local-scope)) a-body))
                     . ,(append (map (lambda-lift local-scope) (cdr term))
                                extension)))
                 (map (lambda-lift local-scope) term)))
            (else (error "I don't know what this is: " term))))))

(define (perform-lambda-lift term)
  ((lambda-lift '()) (car (lambda-lift-annotate term))))

