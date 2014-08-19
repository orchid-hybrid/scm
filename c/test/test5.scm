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


(lambda (l) (if (null? l)
      777
      (begin
        (print l)
        (print-list (cdr l)))))

(lambda (l)
  (boolean (null? l)
           (lambda () 777)
           (lambda ()
             ((lambda () (print-list (cdr l)))
              (print l)))))

(make-closure
  (lambda (env l)
    (invoke-closure
      (vector-ref env 0)
      (invoke-closure (vector-ref env 1) l)
      (make-closure (lambda (env) 777) (vector))
      (make-closure
        (lambda (env)
          (invoke-closure
            (make-closure
              (lambda (env)
                (invoke-closure
                  (vector-ref env 0)
                  (invoke-closure (vector-ref env 1) (vector-ref env 2))))
              (vector print-list cdr l)) ;;;;;;; l is in scope but it should be referenced through env...
            (invoke-closure (vector-ref env 3) (vector-ref env 2))))
        (vector print-list cdr l print))))
  (vector boolean null? print-list cdr print))
