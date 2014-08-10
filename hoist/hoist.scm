;; depends on list.scm, gensym.scm, collector.scm, traverse.scm

(define (hoist collect)
  (traverse (lambda (v)
              v)
            (lambda (args body)
              (let* ((hoisted-body ((hoist collect) body))
                     (name (generate-symbol "lambda")))
                (collect `(define ,name (lambda ,args ,hoisted-body)))
                name))
            (lambda (terms)
              (map (hoist collect) terms))))
