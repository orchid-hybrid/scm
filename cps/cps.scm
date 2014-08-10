;; requires utility/gensym.scm

(define (self-evaluating? e)
  ;; self evaluating forms
  ;; TODO
  (or (symbol? e)
      (quote-form? e)))

(define (quote-form? e)
  (and (list? e)
       (= (length e) 2)
       (equal? 'quote (car e))))

(define (begin-form? e)
  (and (list? e)
       (>= (length e) 1)
       (equal? (car e) 'begin)))

(define (lambda-form? e)
  (and (list? e)
       (>= (length e) 3)
       (equal? (car e) 'lambda)
       (list? (cadr e))
       ;; all symbols cadr
       ))

(define (cps-program e) (cps e 'halt))
(define (cps e c)
  (cond ((self-evaluating? e) `(,c ,e))
        
        ((and (begin-form? e)
              (not (= (length e) 1))) ;; TODO
           (if (= (length e) 2)
               (cps (cadr e) c)
               (let ((ig (generate-symbol "ig")))
                 (cps (cadr e)
                      `(lambda (,ig) ,(cps `(begin . ,(cddr e)) c))))))
        
        ((lambda-form? e)
         (let ((bound-variables (cadr e))
               (body (cddr e)))
           (let ((k (generate-symbol "k")))
             `(,c (lambda (,k . ,bound-variables)
                    ,(cps `(begin . ,body) k))))))
        
        ((list? e) ;; application
         (define (continuation-body fresh-vars parameters continuation)
           (if (null? parameters)
               continuation
               (if (and (self-evaluating? (car parameters))
                        (not fresh-vars))
                   (continuation-body
                    (if fresh-vars (cdr fresh-vars) #f)
                    (cdr parameters)
                    (append continuation (list (car parameters))))
                   (let ((p (if fresh-vars
                                (car fresh-vars)
                                (generate-symbol "p")))) ;; use lambda ones in optimization
                     (cps (car parameters)
                          `(lambda (,p)
                             ,(continuation-body
                               (if fresh-vars (cdr fresh-vars) #f)
                               (cdr parameters)
                               (append continuation (list p)))))))))
         (let ((r (generate-symbol "r")))
           (if (lambda-form? (car e))
               (continuation-body (cadr (car e)) (cdr e) (cps (caddr e) c))
               (if (self-evaluating? (car e))
                   (continuation-body #f (cdr e) `(,(car e) ,c))
                   (cps (car e)
                        `(lambda (,r)
                           ,(continuation-body #f (cdr e) `(,r ,c))))))))

        (else (error `(syntax error ,e)))))
