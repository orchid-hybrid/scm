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

(define (fold kons knil klist)
  (if (null? klist)
      knil
      (kons (car klist)
            (fold kons knil (cdr klist)))))

(define (list-index* i elt list)
  (if (null? list)
      #f
      (if (equal? elt (car list))
          i
          (list-index* (+ i 1) elt (cdr list)))))
(define (list-index elt list)
  (list-index* 0 elt list))

(define (assoc k l)
  (if (null? l)
      #f
      (if (equal? k (caar l))
          (car l)
          (assoc k (cdr l)))))

(define (concat-map f l)
  (if (null? l)
      '()
      (append (f (car l))
              (concat-map f (cdr l)))))
