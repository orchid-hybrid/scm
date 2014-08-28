(define (equal? p q)
  (cond ((and (procedure? p) (procedure? q)) #f)
        ((and (number? p) (number? q)) (= p q))
        ((and (boolean? p) (boolean? q))
         (or (and p q)
             (and (not p) (not q))))
        ((or (and (symbol? p) (symbol? q))
             (and (char? p) (char? q))
             (and (string? p) (string? q)))
         (eq? p q))
        ((and (null? p) (null? q))
         #t)
        ((and (pair? p) (pair? q))
         (and (equal? (car p) (car q))
              (equal? (cdr p) (cdr q))))
        (#t #f)))

(define (eof-object? e)
  (and (number? e)
       (= (- 0 1) e)))

(define (revappend l r)
  (if (null? l)
      r
      (revappend (cdr l) (cons (car l) r))))

(define (reverse l)
  (revappend l '()))

(define (member s l)
  (if (null? l)
      #f
      (or (equal? s (car l))
          (member s (cdr l)))))

(define alphabetic-chars (string->list "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"))
(define numeric-chars (string->list "1234567890"))
(define (char-alphabetic? c)
  (member c alphabetic-chars))
(define (char-numeric? c)
  (member c numeric-chars))

(define (tostring obj)
  (cond
   ((string? obj) obj)
   ((char? obj) (char->string obj))
   ((boolean? obj) (if obj "#t" "#f"))
   ((procedure? obj) "#<procedure>")
   ((number? obj) (number->string obj))
   ((symbol? obj) (symbol->string obj))
   ((null? obj) "()")
   ((list? obj) (foldl string-append "(" (append (map (lambda (s) (string-append (tostring s) " ")) obj) (cons ")" '()))))
   ((pair? obj) (foldl string-append "(" (cons (tostring (car obj))
                                               (cons " . "
                                                     (cons (tostring (cdr obj))
                                                           (cons ")" '()))))))))

(define (display obj)
  (put-string (tostring obj)))

(define (print obj)
  (display obj)
  (newline))

(define (not b)
  (if b #f #t))

(define (make-cell v)
  (cons 'cell v))

(define (set-cell! cell value)
  (set-cdr! cell value))

(define (cell-value cell)
  (cdr cell))


(define (list->string lst)
  (foldr (lambda (c m) (string-append (char->string c) m)) "" lst))

(define (length lst)
  (if (null? lst)
      0
      (+ 1 (length (cdr lst)))))

(define (list? lst)
  (or (null? lst)
      (and (pair? lst)
           (list? (cdr lst)))))

(define (append l m)
  (if (null? l)
      m
      (cons (car l) (append (cdr l) m))))

(define (foldl fn init lst)
  (if (null? lst)
      init
      (foldl fn (fn init (car lst)) (cdr lst))))

(define (foldr fn init lst)
  (if (null? lst)
      init
      (fn (car lst) (foldr fn init (cdr lst)))))

(define (map fn lst)
  (if (null? lst)
      '()
      (cons (fn (car lst)) (map fn (cdr lst)))))

(define (for-each fn lst)
  (if (null? lst)
      '()
      (begin (fn (car lst))
             (for-each fn (cdr lst)))))

(define (caar x) (car (car x)))
(define (cadr x) (car (cdr x)))
(define (cdar x) (cdr (car x)))
(define (cddr x) (cdr (cdr x)))
(define (caaar x) (car (car (car x))))
(define (caadr x) (car (car (cdr x))))
(define (cadar x) (car (cdr (car x))))
(define (caddr x) (car (cdr (cdr x))))
(define (cdraar x) (cdr (car (car x))))
(define (cdadr x) (cdr (car (cdr x))))
(define (cddar x) (cdr (cdr (car x))))
(define (cdddr x) (cdr (cdr (cdr x))))
(define (caaaar x) (car (car (car (car x)))))
(define (caaadr x) (car (car (car (cdr x)))))
(define (caadar x) (car (car (cdr (car x)))))
(define (caaddr x) (car (car (cdr (cdr x)))))
(define (cadaar x) (car (cdr (car (car x)))))
(define (cadadr x) (car (cdr (car (cdr x)))))
(define (caddar x) (car (cdr (cdr (car x)))))
(define (cadddr x) (car (cdr (cdr (cdr x)))))
(define (cdaaar x) (cdr (car (car (car x)))))
(define (cdaadr x) (cdr (car (car (cdr x)))))
(define (cdadar x) (cdr (car (cdr (car x)))))
(define (cdaddr x) (cdr (car (cdr (cdr x)))))
(define (cddaar x) (cdr (cdr (car (car x)))))
(define (cddadr x) (cdr (cdr (car (cdr x)))))
(define (cdddar x) (cdr (cdr (cdr (car x)))))
(define (cddddr x) (cdr (cdr (cdr (cdr x)))))

(define y-combinator-1
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg) ((g g) arg)))))))

(define y-combinator-2
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg1 arg2) ((g g) arg1 arg2)))))))

(define y-combinator-3
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg1 arg2 arg3) ((g g) arg1 arg2 arg3)))))))

(define y-combinator-4
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg1 arg2 arg3 arg4) ((g g) arg1 arg2 arg3 arg4)))))))

(define y-combinator-5
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg1 arg2 arg3 arg4 arg5) ((g g) arg1 arg2 arg3 arg4 arg5)))))))

(define y-combinator-6
  (lambda (f)
    ((lambda (x) (x x))
     (lambda (g)
       (f (lambda (arg1 arg2 arg3 arg4 arg5 arg6) ((g g) arg1 arg2 arg3 arg4 arg5 arg6)))))))
