(define (make-cell v)
  (cons 'cell v))
(define (set-cell! cell value)
  (set-cdr! cell value))
(define (cell-value cell)
  (cdr cell))

(define (make-collector)
  (let ((list (make-cell '()))
        (last (make-cell '())))
    (cons (lambda ()
            (cell-value list))
          (lambda (value)
            (if (null? (cell-value last))
                (begin
                  (set-cell! list (cons value '()))
                  (set-cell! last (cell-value list)))
                (begin
                  (set-cdr! (cell-value last) (cons value '()))
                  (set-cell! last (cdr (cell-value last)))))))))

(define (print-list l)
  (if (null? l)
      777
      (begin
        (print (car l))
        (print-list (cdr l)))))

(define (moo)
  (let ((cell (make-collector)))
    (let ((get (car cell))
          (push (cdr cell)))
      (begin
        (push 'a)
        (push 'b)
        (push 'c)
        (print-list (get))
        (newline)
        (push 'x)
        (push 'y)
        (push 'z)
        (push 'w)
        (print-list (get))
        (newline)))))

