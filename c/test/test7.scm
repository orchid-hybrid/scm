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

(define (set-intersect set-1 set-2)
  (if (null? set-1)
      set-1
      (if (member (car set-1) set-2)
          (cons (car set-1) (set-intersect (cdr set-1) set-2))
          (set-intersect (cdr set-1) set-2))))

(define (moo)
  (print-list (set-intersect '(p i y h g f r r f c m n j h y g b)
                             '(a z x c d s w e r t y g f k b v i))))

