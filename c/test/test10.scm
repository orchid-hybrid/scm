(define (append l m)
 (if (null? l)
     m
     (cons (car l) (append (cdr l) m))))


(define (p0) '())
(define (p1) '(o))
(define (p2) '(o o))
(define (p3) '(o o o))
(define (p4) '(o o o o))
(define (p5) '(o o o o o))
(define (p6) '(o o o o o o))
(define (p7) '(o o o o o o o))
(define (p8) '(o o o o o o o o))
(define (p9) '(o o o o o o o o o))
(define (p10) '(o o o o o o o o o o))

(define (pzero? x) (null? x))

(define (peq? x y)
  (if (pzero? x)
      (pzero? y)
      (if (pzero? y)
 (pzero? x)
 (peq? (cdr x) (cdr y)))))
      

(define (pplus x y) (append x y))


(define (pmul x y)
  (if (pzero? x)
  x
  (if (pzero? y)
  y
  (if (peq? (p1) x)
  y
  (if (peq? (p1) y)
  x
  (pplus y (pmul (cdr x) y)))))))

(define (base1-fib a b)
  (lambda () (cons a (base1-fib b (append a b)))))

(define (take n ss)
  (if (null? n)
      '()
      (cons (car (ss)) (take (cdr n) (cdr (ss))))))

(define (print-list l)
  (if (null? l)
      777
      (begin
        (print (car l))
        (print-list (cdr l)))))

(define (print-list-list l)
  (if (null? l)
      777
      (begin
        (begin (print-list (car l)) (newline))
        (print-list-list (cdr l)))))

(define (print-list-forever l)
  (begin
    (begin (print-list (car (l))) (newline))
    (print-list-forever (cdr (l)))))

(define (moo)
  (begin (print-list-list (take (pmul (p3) (p8)) (base1-fib (cons "1" '()) (cons "1" '()))))
         (newline)))


