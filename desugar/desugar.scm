;; http://matt.might.net/articles/desugaring-scheme/

;; need to lift up "define" vars to the top of lexical scope
;; but they aren't actually set! until their original position
;; (define (a) (b))
;; (a) => error
;; (define (b) 1)
;; (a) => 1


;; checklist
;; ----
;; define
;; let - done
;; let* - done
;; letrec
;; cond - done
;; and
;; or

(define (term-set!? e)
  (and (list? e)
       (= (length e) 3)
       (equal? (car e) 'set!)))

(define (term-var? exp) (symbol? exp))
(define (term-lambda? exp)
  (and (list? exp)
       (= 3 (length exp))
       (equal? 'lambda (car exp))
       (list? (cadr exp))))

(define (term-app? exp)
  (and (list? exp)
       (or (term-lambda? (car exp))
           (term-var? (car exp)))))

;; (let ((a b)) c)
(define (term-let? exp)
  (and (list? exp)
       (>= (length exp) 3)
       (list? (cadr exp))
       (equal? 'let (car exp))))

(define (term-let*? exp)
  (and (list? exp)
       (>= (length exp) 3)
       (list? (cadr exp))
       (equal? 'let* (car exp))))

;; (define a b)
(define (term-define? exp)
    (and (list? exp)
         (= (length exp) 3)
         (symbol? (cadr exp))
         (equal? 'define (car exp))))

;; (define (foo bar) bar)
(define (term-define-procedure? exp)
  (and  (list? exp)
        (>= (length exp) 3)
        (list? (cadr exp))
        (equal? 'define (car exp))))

(define (term-cond? exp)
  (and (list? exp)
       (equal? 'cond (car exp))))

(define (desugar exp)
  (cond
    ((term-set!? exp) `(set! ,(cadr exp) ,(desugar (caddr exp))))
    
    ((term-let? exp)
     (let* ((bindings (cadr exp))
            (params (map car bindings))
            (values (map cadr bindings))
            (body (cddr exp)))
       `((lambda ,params . ,(map desugar body)) . ,(map desugar values))))
    
    ((term-let*? exp)
     (let* ((bindings (cadr exp))
            (body (cddr exp)))
       (desugar
        (append `(let (,(car bindings)))
                (if (null? (cdr bindings))
                    body
                    `((let* ,(cdr bindings) . ,body)))))))
    
    ;; (define foo 1)
    ((term-define? exp)
     (let ((name (cadr exp))
           (value (caddr exp)))
       (desugar `(let ((,name '()))
                   (set! ,name ,(desugar value))))))
    
    ;; (define (foo a) a ...)
    ((term-define-procedure? exp)
     (let ((name (caadr exp))
           (params (cdadr exp))
           (body (cddr exp)))
       (desugar `(define ,name (lambda ,params . ,body)))))
    
    
    ;; cond
    ((term-cond? exp)
     (cond
       ;; (cond)
       ((equal? '(cond) exp) '(void))
       ;; (cond (else b)
       ((and (equal? 'else (caadr exp))
             (= 2 (length exp)))
        (desugar (cadadr exp)))
       ;; (cond (a b))
       ((= 2 (length exp))
            `(if ,(desugar (caadr exp))
                ,(desugar (cadadr exp))
                (void)))
       ;; (coond (a b) rest ...)
       ((> (length exp) 2)
        `(if ,(desugar (caadr exp))
             ,(desugar (cadadr exp))
             ,(desugar `(cond . ,(cddr exp)))))))
    
    
    ((term-var? exp) exp)
    ((term-app? exp) (map desugar exp))
    (else exp)))

(define (test-let)
  (equal? (desugar '(let ((a 1)) a))
          '((lambda (a) a) 1)))

(define (test-let*)
  (equal? (desugar '(let* ((a 1)(b a)) (+ a b)))
          '((lambda (a) ((lambda (b) (+ a b)) a)) 1)))