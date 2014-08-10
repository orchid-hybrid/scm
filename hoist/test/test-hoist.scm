(define (test-hoist t)
  (let ((collector (make-collector)))
    (let ((result ((hoist (cdr collector)) t)))
      (for-each pretty-print ((car collector)))
      (newline)
      (pretty-print result))))

;;(begin
;;  (test-hoist '(f (lambda () (f (lambda (x) x))) (lambda () (g (lambda (y) (x y)))) z)))
