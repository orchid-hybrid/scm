(define lambda0 (lambda (env a b) (invoke-closure (vector-ref env 0) b)))
(define lambda1
  (lambda (env f)
    (invoke-closure
      (make-closure lambda0 (vector f))
      (invoke-closure f "Hello")
      "World")))
(define lambda2 (lambda (env s) (invoke-closure (vector-ref env 0) s)))

(invoke-closure
  (make-closure lambda1 (vector))
  (make-closure lambda2 (vector (make-closure print (vector)))))
