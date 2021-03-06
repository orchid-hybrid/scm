(define (equal? p q)
  (cond ((and (procedure? p) (procedure? q)) #f)
        ((and (number? p) (number? q)) (= p q))
        ((and (boolean? p) (boolean? q))
         (or (and p q)
             (and (not p) (not q))))
        ((or (and (symbol? p) (symbol? q))
             (and (string? p) (string? q)))
         (eq? p q))
        ((and (null? p) (null? q))
         #t)
        ((and (pair? p) (pair? q))
         (and (equal? (car p) (car q))
              (equal? (cdr p) (cdr q))))
        (#t #f)))

(define (moo)
  (begin (if (equal? moo moo)
             (print "equal")
             (print "not equal"))
         (if (equal? 55 75)
             (print "equal")
             (print "not equal"))
         (if (equal? (+ 50 5) 55)
             (print "equal")
             (print "not equal"))
         (if (equal? (null? '()) (null? '(foo)))
             (print "equal")
             (print "not equal"))
         (if (equal? (null? '(bar baz)) (null? '(foo)))
             (print "equal")
             (print "not equal"))
         (if (equal? '(a b 22 (d #f f (g h i)))
                     '(a b 22 (d #f f (g h i))))
             (print "equal")
             (print "not equal"))
         (if (equal? '(a b 22 (d #f f (g h i)))
                     '(a b 22 (d #f x (g h i))))
             (print "equal")
             (print "not equal"))
         )))
