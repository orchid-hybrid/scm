(define (all p l)
  (if (null? l)
      #t
      (if (p (car l))
          (all p (cdr l))
          #f)))

(define (any p l)
  (if (null? l)
      #f
      (if (p (car l))
          #t
          (any p (cdr l)))))

(define (list-index* i elt list)
  (if (null? list)
      #f
      (if (equal? elt (car list))
          i
          (list-index* (+ i 1) elt (cdr list)))))
(define (list-index elt list)
  (list-index* 0 elt list))

(define (moo)
  (print (all (lambda (x) (= x 1))
              '(1 1 1)))
  (print (all (lambda (x) (= x 1))
              '(1 2 1)))
  (print (any (lambda (x) (= x 2))
              '(1 1 1)))
  (print (any (lambda (x) (= x 2))
              '(1 2 1)))
  (print (list-index 2 '(1 1 23 34645 87 6 5 11 1 1 1 2 3 48 9 7 5 4 35))))
