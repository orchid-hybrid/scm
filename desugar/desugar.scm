;; http://matt.might.net/articles/desugaring-scheme/

;; checklist
;; ----
;; define
;; let - done
;; let* - done
;; if - done
;; cond - done
;; and - done
;; or - done
;; quote - done
;; quasiquote
;; unquote 

(define (term-set!? e)
  (and (list? e)
       (= (length e) 3)
       (equal? (car e) 'set!)))

(define (term-begin? e)
  (and (list? e)
       (>= (length e) 1)
       (equal? (car e) 'begin)))

(define (term-var? exp) (symbol? exp))
(define (term-lambda? exp)
  (and (list? exp)
       (>= (length exp) 3)
       (equal? 'lambda (car exp))
       (or (null? (cadr exp)) ;; allow empty parameter lists
           (list? (cadr exp)))))

(define (term-app? exp)
  (and (list? exp)
       (not (null? exp))
       (or (term-lambda? (car exp))
           (term-var? (car exp))
           (list? (car exp)))))

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

(define (term-if? exp)
  (and (list? exp)
       (= (length exp) 4)
       (equal? 'if (car exp))))

(define (term-cond? exp)
  (and (list? exp)
       (not (null? exp))
       (equal? 'cond (car exp))))

(define (term-and? exp)
  (and (list? exp)
       (>= (length exp) 1)
       (equal? 'and (car exp))))

(define (term-or? exp)
  (and (list? exp)
       (>= (length exp) 1)
       (equal? 'or (car exp))))

(define (term-quote? exp)
  (and (list? exp)
       (= (length exp) 2)
       (equal? 'quote (car exp))))

(define (term-quasiquote? exp)
  (and (list? exp)
       (= (length exp) 2)
       (equal? 'quasiquote (car exp))))

(define (term-unquote? exp)
  (and (list? exp)
       (= (length exp) 2)
       (equal? 'unquote (car exp))))

(define (term-begin? e)
  (and (list? e)
       (>= (length e) 1)
       (equal? (car e) 'begin)))

(define (desugar exp)
  (cond
   ((term-set!? exp) `(set! ,(cadr exp) ,(desugar (caddr exp))))
 
   ((term-begin? exp)
    (cond ((null? (cdr exp)) (error "empty begin form"))
          ((null? (cddr exp)) (desugar (cadr exp)))
          (else `((lambda ()
                    ,(desugar (cons 'begin (cddr exp))))
                  ,(desugar (cadr exp))))))
   
   ((term-lambda? exp)
    (let ((params (cadr exp))
          (body (cddr exp)))
      `(lambda ,params ,(desugar (cons 'begin body)))))

   ((term-let? exp)
    (let* ((bindings (cadr exp))
	   (params (map car bindings))
	   (values (map cadr bindings))
	   (body (cddr exp)))
      (desugar `((lambda ,params . ,body) . ,values))))
   
   ((term-let*? exp)
    (let* ((bindings (cadr exp))
	   (body (cddr exp)))
      (desugar
       (append `(let (,(car bindings)))
               (if (null? (cdr bindings))
                   body
                   `((let* ,(cdr bindings) . ,body)))))))

   ((term-define-procedure? exp)
    (let ((name (caadr exp))
	  (params (cdadr exp))
	  (body (cddr exp)))
      `(define ,name ,(desugar `(lambda ,params . ,body)))))
   
   ((term-if? exp)
    (let ((b (cadr exp))
	  (then (caddr exp))
	  (else (cadddr exp)))
      `(boolean ,(desugar b)
		(lambda () ,(desugar then))
		(lambda () ,(desugar else)))))
   
   ((term-cond? exp)
    (cond
     ;; (cond)
     ((equal? '(cond) exp) '())
     ;; (cond (else b))
     ((and (equal? 'else (caadr exp))
	   (= 2 (length exp)))
      (desugar (cadadr exp)))
     ;; (cond (a b))
     ((= 2 (length exp))
      (desugar `(if ,(caadr exp)
                    ,(cadadr exp)
                    '())))
     ;; (coond (a b) rest ...)
     ((> (length exp) 2)
      (desugar `(if ,(caadr exp)
                    ,(cadadr exp)
                    (cond . ,(cddr exp)))))))
   
   ((term-and? exp)
    (if (null? (cdr exp))
        #t
        (desugar `(if ,(cadr exp) ,(cons 'and (cddr exp)) #f))))
   
  ((term-or? exp)
    (if (null? (cdr exp))
        #f
        (desugar `(if ,(cadr exp) #t ,(cons 'or (cddr exp))))))
   
    ((term-quote? exp)
     (quote-desugar (cadr exp)))
    ((term-quasiquote? exp)
     (quasiquote-desugar (cadr exp)))
    ((term-unquote? exp)
     (error "unquote"))
    
    ((term-var? exp) exp)
    ((term-app? exp)
     (if (equal? (car exp) 'list)
         (fold (lambda (x ys)
                 (list 'cons (desugar x) ys))
               ''()
               (cdr exp))
         (map desugar exp)))
    (else exp)))

(define (quote-desugar term)
  (cond
   ((pair? term)
    `(cons ,(quote-desugar (car term))
           ,(quote-desugar (cdr term))))
   (else `(quote ,term))))

(define (quasiquote-desugar term)
  (cond
   ((term-unquote? term)
    (desugar (cadr term)))
   ((pair? term)
    `(cons ,(quasiquote-desugar (car term))
           ,(quasiquote-desugar (cdr term))))
   (else (desugar `(quote ,term)))))

(define (test-let)
  (equal? (desugar '(let ((a 1)) a))
          '((lambda (a) a) 1)))

(define (test-let*)
  (equal? (desugar '(let* ((a 1)(b a)) (+ a b)))
          '((lambda (a) ((lambda (b) (+ a b)) a)) 1)))

(define (test-if)
  (equal? (desugar '(if b thn els))
          '(bool b (lambda () thn) (lambda () els))))

(define (test-quasi)
  (pretty-print (quasiquote-desugar '(f x ,y z)))
  (pretty-print (quasiquote-desugar '(make-closure (lambda (env . ,args) ,((closure-convert free-variables) body))
                                                   (vector . ,free-variables)))))
