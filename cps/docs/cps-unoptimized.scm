;;; gensym

(define symbol-table '())

(define (symbol-add s)
  ;; Add the symbol s to the symbol-table
  ;; unless it's already in there.
  ;; Returns a #t if the symbol is fresh and
  ;; had to be added, #f if it was already in
  ;; there.
  (if (member s symbol-table)
      #f
      (begin
        (set! symbol-table (cons s symbol-table))
        #t)))

(define (add-all-symbols sexp)
  ;; traverse an s-expression adding every symbol in the tree
  (cond ((symbol? sexp) (symbol-add sexp))
        ((pair? sexp)
         (add-all-symbols (car sexp))
         (add-all-symbols (cdr sexp)))
        (else #f)))

(define (generate-symbol prefix)
  (let loop ((counter 0))
    (let ((s (string->symbol (string-append prefix (number->string counter)))))
      (if (symbol-add s)
          s
          (loop (+ counter 1))))))

;;;

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
         ;; TODO special case for lambda as car
         ;; TODO don't bother evaluating self evaluating forms
         (let ((r (generate-symbol "r")))
           (cps (car e)
                `(lambda (,r)
                   ,(let loop ((parameters (cdr e))
                               (continuation `(,r ,c)))
                      (if (null? parameters)
                          continuation
                          (let ((p (generate-symbol "p")))
                            (cps (car parameters)
                                 `(lambda (,p)
                                    ,(loop (cdr parameters)
                                           (append continuation (list p))))))))))))

        (else (error `(syntax error ,e)))))
