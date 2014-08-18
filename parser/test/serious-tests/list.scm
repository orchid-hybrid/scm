(define (all p l)
  (if (null? l)
      #t
      (if (p (car l))
          (all p (cdr l))
          #f)))

(define (list-index* i elt list)
  (if (null? list)
      #f
      (if (equal? elt (car list))
          i
          (list-index* (+ i 1) elt (cdr list)))))
(define (list-index elt list)
  (list-index* 0 elt list))
