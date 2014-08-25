(define (for-each f l)
  (if (null? l)
      #f
      (begin (f (car l))
             (for-each f (cdr l)))))

(define (for-each-between f comma list)
  (if (null? list) #f
      (if (null? (cdr list))
          (f (car list))
          (begin
            (f (car list))
            (comma)
            (for-each-between f comma (cdr list))))))

(define (test)
  (lambda (i)
    (for-each (lambda (i)
                (print "DOCHY! ")
                (print (number->string i)))
              `(,i ,(+ i 1) ,(+ i 2)))))

(define (test-2)
  (lambda (i)
    (for-each-between
     (lambda (i)
       (print "HAPPY! ")
       (print (number->string i)))
     (lambda () (print "LUCKY! "))
     `(,i ,(+ i 1) ,(+ i 2)))))

(define (moo)
  (begin
    (for-each (test-2) '(67676767 252525 484848))
    (for-each (test) '(67676767 252525 484848))))
