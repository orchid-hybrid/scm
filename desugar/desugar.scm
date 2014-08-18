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
       (= 3 (length exp))
       (equal? 'lambda (car exp))
       (list? (cadr exp))))

(define (term-app? exp)
  (and (list? exp)
       (not (null? exp))
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

(define (term-letrec? exp)
  (and (list? exp)
       (>= (length exp) 3)
       (list? (cadr exp))
       (equal? 'letrec (car exp))))

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
       (= (length exp) 3)
       (equal? 'and (car exp))))

(define (term-or? exp)
  (and (list? exp)
       (= (length exp) 3)
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
    (let loop ((terms (map desugar (cdr exp))))
      (if (null? terms)
	  #f
	  (if (null? (cdr terms))
	      (desugar (car terms))
	      `((lambda () ,(loop (cdr terms))) ,(car terms))))))
   
   
   ;; (let loop ((foo bar)) .... (loop (baz foo)))
   ((term-name-let? exp)
    (let* ((name (cadr exp))
	   (bindings (caddr exp))
	   (params (map car bindings))
	   (values (map cadr bindings))
	   (body (cdddr exp)))
      (desugar `(letrec ((,name `(lambda ,params . body)))
		  (,name . ,values)))))

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
    
    ((term-letrec? exp)
     (let ((bindings (cadr exp))
	   (body (cddr exp)))
       (desugar `(let (map (lambda (p) (list p '(void))) (map car bindings))
		   ,@(map (lambda (b) `(set! ,(car b) ,(cadr b))) bindings)
                   ,@body))))

    ;; (define foo 1)
    ((term-define? exp)
     (let ((name (cadr exp))
           (value (caddr exp)))
       (desugar `(let ((,name (void)))
                   (set! ,name ,(desugar value))))))
    
    ;; (define (foo a) a ...)
    ((term-define-procedure? exp)
     (let ((name (caadr exp))
           (params (cdadr exp))
           (body (cddr exp)))
       (desugar `(define ,name (lambda ,params . ,body)))))
    
    ;; if
    ((term-if? exp)
     (let ((b (cadr exp))
           (then (caddr exp))
           (else (cadddr exp)))
       `(boolean ,(desugar b)
                 (lambda () ,(desugar then))
                 (lambda () ,(desugar else)))))
    
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
    
    ((term-and? exp)
     (let ((v1 (cadr exp))
           (v2 (caddr exp)))
       (desugar `(if ,v1 ,v2 #f))))
    
    ((term-or? exp)
     (let ((v1 (cadr exp))
           (v2 (caddr exp)))
       (desugar `(if ,v1 #t ,v2))))
    
    ((term-quote? exp)
     exp)
    ((term-quasiquote? exp)
     (quasiquote-desugar (cadr exp)))
    ((term-unquote? exp)
     (error "unquote"))
    
    ((term-var? exp) exp)
    ((term-app? exp) (map desugar exp))
    (else exp)))

(define (quasiquote-desugar term)
  (cond
   ((term-unquote? term)
    (cadr term))
   ((pair? term)
    `(cons ,(quasiquote-desugar (car term))
           ,(quasiquote-desugar (cdr term))))
   (else `(quote ,term))))

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
