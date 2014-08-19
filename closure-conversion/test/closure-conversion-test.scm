
(begin
  (let ((f (lambda (t)
             (let ((f (annotate-free-variables t)))
               (pretty-print t)
               (pretty-print (car f))
               (pretty-print ((closure-convert '()) (car f)))
               (newline)))))
    (f 'x)
    (f '(f x y z))
    (f '(lambda (x) x))
    (f '(f (lambda (x) x) (lambda (y) y) (lambda (z) z)))
    (f '(f (lambda (x u) (h i j (lambda (v w) (w u u u v)) l)) y z))
    (f '(lambda (a) (lambda (b) (lambda (c) a))))

    ))

