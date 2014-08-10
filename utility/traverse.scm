;; This helps write recursion over lambda terms
;; by doing case analysis on the terms for you

;; Form predicates

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

(define (traverse string-case number-case variable-case lambda-case application-case)
  ;; t ::= v
  ;;     | (lambda (v ...) t)
  ;;     | (t ...)
  (lambda (t)
    (cond ((string? t)
           (string-case t))
          ((number? t)
           (number-case t))
          ((variable-form? t)
           (variable-case t))
          ((lambda-form? t)
           (lambda-case (cadr t)
                        (caddr t)))
          ((application-form? t)
           (application-case t))
          (else (error (cons t "traverse"))))))

(define (traverse* string-case number-case variable-case lambda*-case application-case)
  ;; f ::= v
  ;;     | (lambda* (v ...) (v ...) f)
  ;;                        ^^^^^^--- free variables added here
  ;;     | (f ...)
  (lambda (t)
    (cond ((string? t)
           (string-case t))
          ((number? t)
           (number-case t))
          ((variable-form? t)
           (variable-case t))
          ((lambda*-form? t)
           (lambda*-case (cadr t)
                         (caddr t)
                         (cadddr t)))
          ((application-form? t)
           (application-case t))
          (else (error "traverse*")))))
