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

(define (tee)
  (traverse display display display display (lambda (q) (display "quote") (display q)) (lambda (v) (display "variable") (display v)) (lambda (args body) (display "lambda") (display args) (display "&") (( tee) body) (newline)) (lambda (terms) (display "application") (map (tee) terms) (newline))))

(define (moo)
  (begin
    (display (set-union '(a h u e d f v c)
                        '(o k n u h b y g v)))
    (newline)
    
    (display (set-intersect '(a h u e d f v c)
                            '(o k n u h b y g v)))
    (newline)
    
    (display (list-index 'h '(o k n u h b y g v)))
    (newline)
    
    (display (variable-form? 'x)) (newline)
    (display (variable-form? '(f x))) (newline)
    (display (lambda-form? 'x)) (newline)
    (display (lambda-form? '(x y))) (newline)
    (display (lambda-form? '(lambda (x) y))) (newline)
    (display (application-form? 'x)) (newline)
    (display (application-form? '(f x))) (newline)

    (display (set-union '(a h u e d f v c)
                        '(o k n u h b y g v)))
    (newline)
    
    (display (set-intersect '(a h u e d f v c)
                            '(o k n u h b y g v)))
    (newline)
    
    (display (list-index 'h '(o k n u h b y g v)))
    (newline)
    
    (display (variable-form? 'x)) (newline)
    (display (variable-form? '(f x))) (newline)
    (display (lambda-form? 'x)) (newline)
    (display (lambda-form? '(x y))) (newline)
    (display (lambda-form? '(lambda (x) y))) (newline)
    (display (application-form? 'x)) (newline)
    (display (application-form? '(f x))) (newline)

    (( tee) '(lambda (x) (f x y z)))
    (( tee) '(lambda (x) (f x y z)))
    ))
