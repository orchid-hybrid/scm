;; depends on list.scm, set.scm, traverse.scm

(define annotate-free-variables
  ;; This traverses a lambda term changing lambda to
  ;; lambda* by adding the list of free variables
  (traverse (lambda (s)
              (cons s '()))
            (lambda (c)
              (cons c '()))
            (lambda (n)
              (cons n '()))
            (lambda (b)
              (cons b '()))
             (lambda (q)
               (cons `(quote ,q) '()))
            (lambda (v)
              (cons v (list v)))
            (lambda (args body)
              (let ((body-result (annotate-free-variables body)))
                (let ((annotated-body (car body-result))
                      (free-variables (set-remove (cdr body-result) args)))
                  (cons `(lambda* ,args ,free-variables ,annotated-body)
                        free-variables))))
            (lambda (terms)
              (let ((terms-result (map annotate-free-variables terms)))
                (cons (map car terms-result)
                      (set-union* (map cdr terms-result)))))))

(define (closure-convert free-variables)
  ;; This traverses a lambda* term, closing over all free
  ;; variables by making then into environments
  (traverse* (lambda (s)
               s)
             (lambda (c)
               c)
             (lambda (n)
               n)
             (lambda (b)
               b)
             (lambda (q)
               `(quote ,q))
             (lambda (v)
               (let ((i (list-index v free-variables)))
                 (if i
                     `(vector-ref env ,i)
                     v)))
             (lambda (args new-free-variables body)
               `(make-closure (lambda (env . ,args) ,((closure-convert new-free-variables) body))
                              (vector . ,(map (closure-convert free-variables) new-free-variables))))
             (lambda (terms)
               (if (and (not (null? terms))
                        (equal? (car terms) 'quote))
                   terms
                   `(invoke-closure . ,(map (closure-convert free-variables) terms))))))

(define (perform-closure-conversion term)
  (let ((a (annotate-free-variables term)))
    ((closure-convert '()) (car a))))

