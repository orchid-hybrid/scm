;; depends on list.scm, gensym.scm, collector.scm, traverse.scm


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



;; This lets you do set operations on lists of symbols
;; It is mostly used for 

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

(define (filter set-1 set-2)
  (if (null? set-2)
      set-2
      (if (member (car set-2) set-1)
          (filter set-1 (cdr set-2))
          (cons (car set-2) (filter set-1 (cdr set-2))))))

(define (set-union set-1 set-2)
  (append set-1 (filter set-1 set-2)))

(define (set-union* sets)
  (if (null? sets)
      sets
      (set-union (car sets) (set-union* (cdr sets)))))



(define (variable-form? t)
  (symbol? t))

(define (lambda-form? t)
  (and (list? t)
       (= 3 (length t))
       (equal? 'lambda (car t))
       (list? (cadr t))
       (all variable-form? (cadr t))))

(define (lambda*-form? t)
  (and (list? t)
       (= 4 (length t))
       (equal? 'lambda* (car t))
       (list? (cadr t))
       (all variable-form? (cadr t))
       (all variable-form? (caddr t))))

(define (application-form? t)
  (list? t))

;; Traversal functions

(define (traverse string-case char-case number-case boolean-case quote-case variable-case lambda-case application-case)
  ;; t ::= v
  ;;     | (lambda (v ...) t)
  ;;     | (t ...)
  (lambda (t)
    (cond ((string? t)
           (string-case t))
          ((char? t)
           (char-case t))
          ((number? t)
           (number-case t))
          ((boolean? t)
           (boolean-case t))
          ((and (list? t)
                (= (length t) 2)
                (equal? (car t) 'quote))
           (quote-case (cadr t)))
          ((variable-form? t)
           (variable-case t))
          ((lambda-form? t)
           (lambda-case (cadr t)
                        (caddr t)))
          ((application-form? t)
           (application-case t))
          (else (error "traverse")))))



(define (make-cell v)
  (cons 'cell v))
(define (set-cell! cell value)
  (set-cdr! cell value))
(define (cell-value cell)
  (cdr cell))

(define (make-collector)
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






;; This implements gensym, a fresh name generator
;; it stores all the symbols it's previously created
;; and makes sure it only hands out something never
;; seen before

(define (member s l)
  (if (null? l)
      #f
      (or (equal? s (car l))
          (member s (cdr l)))))

(define symbol-table (make-cell '()))

(define (symbol-add s)
  ;; Add the symbol s to the symbol-table
  ;; unless it's already in there.
  ;; Returns a #t if the symbol is fresh and
  ;; had to be added, #f if it was already in
  ;; there.
  (if (member s (cell-value symbol-table))
      #f
      (begin
        (set-cell! symbol-table (cons s (cell-value symbol-table)))
        #t)))

(define (add-all-symbols sexp)
  ;; traverse an s-expression adding every symbol in the tree
  (cond ((symbol? sexp) (symbol-add sexp))
        ((pair? sexp)
         (add-all-symbols (car sexp))
         (add-all-symbols (cdr sexp)))
        (else #f)))

(define (generate-symbol prefix)
  (let loop ((counter 0))
    (let ((s (string->symbol (string-append prefix (number->string counter)))))
      (if (symbol-add s)
          s
          (loop (+ counter 1))))))





(define (hoist collect)
  (traverse (lambda (s)
              s)
            (lambda (c)
              c)
            (lambda (n)
              n)
            (lambda (b)
              b)
            (lambda (q)
              `(quote ,q))
            (lambda (v)
              v)
            (lambda (args body)
              (let* ((hoisted-body ((hoist collect) body))
                     (name (generate-symbol "lambda")))
                (collect `(define ,name (lambda ,args ,hoisted-body)))
                name))
            (lambda (terms)
              (map (hoist collect) terms))))

(define (test-hoist t)
  (let ((collector (make-collector)))
    (let ((result ((hoist (cdr collector)) t)))
      (for-each display ((car collector)))
      (newline)
      (display result))))

(define (moo) (begin
                (test-hoist '(f (lambda () (f (lambda (x) x))) (lambda () (g (lambda (y) (x y)))) z))))
