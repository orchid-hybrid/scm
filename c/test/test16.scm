(define (test s)
  (cond ((eq? s 'a) (print "AAAA"))
        ((eq? s 'b) (print "BB"))
        ((eq? s 'c) (print "C"))))

(define (moo)
  (begin (test 'b) (test 'c) (test 'b) (test 'a)))
