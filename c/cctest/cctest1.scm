;; depends on list.scm, set.scm, traverse.scm

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




(define annotate-free-variables
  ;; This traverses a lambda term changing lambda to
  ;; lambda* by adding the list of free variables
  (traverse (lambda (s)
              (cons s '()))
            (lambda (c)
              (cons c '()))
            (lambda (n)
              (cons n '()))
            (lambda (b)
              (cons b '()))
             (lambda (q)
               (cons `(quote ,q) '()))
            (lambda (v)
              (cons v (list v)))
            (lambda (args body)
              (let ((body-result (annotate-free-variables body)))
                (let ((annotated-body (car body-result))
                      (free-variables (set-remove (cdr body-result) args)))
                  (cons `(lambda* ,args ,free-variables ,annotated-body)
                        free-variables))))
            (lambda (terms)
              (let ((terms-result (map annotate-free-variables terms)))
                (cons (map car terms-result)
                      (set-union* (map cdr terms-result)))))))

(define (moo)
  (begin
    (let ((f (lambda (t)
               (let ((f (annotate-free-variables t)))
                 (display t) (newline)
                 (display (car f)) (newline)
                 (display (annotate-free-variables (car f))) (newline)
                 (newline)))))
      (f 'x)
      (f '(f x y z))
      (f '(lambda (x) x))
      (f '(f (lambda (x) x) (lambda (y) y) (lambda (z) z)))
      (f '(f (lambda (x u) (h i j (lambda (v w) (w u u u v)) l)) y z))
      (f '(lambda (a) (lambda (b) (lambda (c) a))))

      )))
