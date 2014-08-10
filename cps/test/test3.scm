(pretty-print (cps-program '(f (a) (b) (c))))

(print (list
(let ((f (lambda (a b c) (list a b a c a)))
      (a (lambda () "a"))
      (b (lambda () "b"))
      (c (lambda () "c")))
  (f (a) (b) (c)))
(let ((f (lambda (k a b c) (k (list a b a c a))))
      (a (lambda (k) (k "a")))
      (b (lambda (k) (k "b")))
      (c (lambda (k) (k "c")))
      (halt (lambda (i) i)))
  ((lambda (r0)
     ((lambda (r3)
        (r3 (lambda (p0)
              ((lambda (r2)
                 (r2 (lambda (p1)
                       ((lambda (r1) (r1 (lambda (p2) (r0 halt p0 p1 p2)))) c))))
               b))))
      a))
   f))))

(pretty-print (cps-program '((lambda (a b c) (f c)) a b c)))
(pretty-print (cps-program '((lambda (x y z) (f z y x x y z)) a b c)))


(exit)
