(define (one) 1)

(define (procedure-test)
  (procedure? one))

(define (number-test)
  (number? (one)))

(define (boolean-test)
  (and (boolean? #t)
       (boolean? #f)
       (boolean? ((lambda () #t)))))

(define (symbol-test)
  (symbol? 'q))

(define (string-test)
  (and (string? "lul")
       (not (string? 1))))

(define (null-test)
  (and (null? '())
       (not (null? (cons 1 '())))))

(define (pair-test)
  (and (pair? (cons 1 '()))
       (not (pair? '()))))

(define (moo)
  (if (and (procedure-test) (number-test) (boolean-test)
           (symbol-test) (string-test)
           (null-test) (pair-test))
      (print "type tests pass!")
      (print "type tests fail!")))
