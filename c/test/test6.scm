(define (member elt list)
  (if (null? list)
      #f
      (if (eq? elt (car list))
          list
          (member elt (cdr list)))))

(define (print-list l)
  (if (null? l)
      777
      (begin
        (print (car l))
        (print-list (cdr l)))))

(define (moo)
  (begin (print-list (member 'e '(a b c d e f g)))
         (if (member 'z '(a f g))
             (print "OK")
             (print "NO"))
         (newline)))

