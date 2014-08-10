(define (make-closure f v)
  (cons f v))

(define (invoke-closure f . args)
  (apply (car f) (cons (cdr f) args)))
