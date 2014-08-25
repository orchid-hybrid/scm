(define (moo)
  (begin
    (map
     (lambda (x) (print (number->string (+ x x))))
     (cons 1 (cons 2 (cons 3 '()))))))
