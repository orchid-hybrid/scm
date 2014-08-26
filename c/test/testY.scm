(define y-combinator
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg) ((g g) arg)))))))
 
(define fac
  (y-combinator
    (lambda (f)
      (lambda (x)
        (if (< x 2)
            1
            (* x (f (- x 1))))))))
 
(define fib
  (y-combinator
    (lambda (f)
      (lambda (x)
        (if (< x 2)
            x
            (+ (f (- x 1)) (f (- x 2))))))))
 
(define (moo)
  (display (fac 6))
  (newline)
  (display (fib 6))
  (newline))
