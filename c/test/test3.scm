(define (moo) (((lambda (m n)
                  (lambda (z s)
                    (n (m z s) s)))
                (lambda (z s) (s (s (s z))))
                (lambda (z s) (s (s (s (s (s z)))))))
               "HELLO WORLD!!!"
               (lambda (s)
                 ((lambda (x y)
                    x) s (print s)))))
