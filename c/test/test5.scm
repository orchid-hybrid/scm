(define (get-list)
  '(a b c d e f))

(define (print-list l)
  (if (null? l)
      777
      (begin
        (print l)
        (print-list (cdr l)))))

(define (moo)
  (print-list (get-list)))
