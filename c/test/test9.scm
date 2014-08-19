(define (append l m)
 (if (null? l)
     m
     (cons (car l) (append (cdr l) m))))

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
  (begin (print-list-list (take '(a a a a a) (base1-fib (cons "1" '()) (cons "1" '()))))
         (newline)))
