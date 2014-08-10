(define (make-collector)
  (let ((list '())
        (last '()))
    (cons (lambda ()
            list)
          (lambda (value)
            (if (null? last)
                (begin
                  (set! list (cons value '()))
                  (set! last list))
                (begin
                  (set-cdr! last (cons value '()))
                  (set! last (cdr last))))))))
