(define lambda0
  (lambda (env z s)
    (invoke-closure
      (vector-ref env 0)
      (invoke-closure (vector-ref env 1) z s)
      s)))
(define lambda1 (lambda (env m n) (make-closure lambda0 (vector n m))))
(define lambda2
  (lambda (env z s)
    (invoke-closure s (invoke-closure s (invoke-closure s z)))))
(define lambda3
  (lambda (env z s)
    (invoke-closure
      s
      (invoke-closure
        s
        (invoke-closure s (invoke-closure s (invoke-closure s z)))))))
(define lambda4 (lambda (env x y) x))
(define lambda5
  (lambda (env s)
    (invoke-closure
      (make-closure lambda4 (vector))
      s
      (invoke-closure (vector-ref env 0) s))))

(invoke-closure
  (invoke-closure
    (make-closure lambda1 (vector))
    (make-closure lambda2 (vector))
    (make-closure lambda3 (vector)))
  "HELLO WORLD!!!"
  (make-closure lambda5 (vector (make-closure print (vector)))))
