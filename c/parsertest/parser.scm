;; depends on utility/list.scm

(define (all p l)
  (if (null? l)
      #t
      (if (p (car l))
          (all p (cdr l))
          #f)))

(define (string a b) (string-append (char->string a) (char->string b)))

(define (collector)
  (let ((list (make-cell '()))
        (last (make-cell '())))
    (cons (lambda ()
            (cell-value list))
          (lambda (value)
            (if (null? (cell-value last))
                (begin
                  (set-cell! list (cons value '()))
                  (set-cell! last (cell-value list)))
                (begin
                  (set-cdr! (cell-value last) (cons value '()))
                  (set-cell! last (cdr (cell-value last)))))))))

(define (whitespace? c)
  (or (equal? c #\space)
      (equal? c #\newline)))

(define (symbolic? c)
  (or (char-alphabetic? c)
      (char-numeric? c)
      (equal? #\= c)
      (equal? #\* c)
      (equal? #\- c)
      (equal? #\/ c)
      (equal? #\+ c)
      (equal? #\. c)
      (equal? #\? c)
      (equal? #\! c)
      (equal? #\< c)
      (equal? #\> c)))

(define (skip-whitespace stream)
  (if (whitespace? (peek-char stream))
      (begin (read-char stream)
             (skip-whitespace stream))
      #f))

(define (classify c)
  (cond ((eof-object? c) 'eof)
        ((whitespace? c) 'whitespace)
        ((equal? c #\.) 'dot)
        ((symbolic? c) 'symbolic)
        ((equal? c #\") 'string-quote)
        ((equal? c #\') 'lisp-quote)
        ((equal? c #\`) 'quasi-quote)
        ((equal? c #\,) 'unquote)
        ((equal? c #\() 'open)
        ((equal? c #\;) 'comment)
        ((equal? c #\#) 'hash)
        (else 'unknown)))

(define (read-symbol-aux input-stream sym create-symbol)
  (if (symbolic? (peek-char input-stream))
      (begin
        (sym (read-char input-stream))
        (read-symbol-aux input-stream sym create-symbol))
      (create-symbol (sym))))

(define (read-symbol input-stream)
  (let ((create-symbol (lambda (cs)
                         (if (all char-numeric? cs)
                             (string->number (list->string cs))
                             (string->symbol (list->string cs))))))
    (read-symbol-aux input-stream (collector) create-symbol)))


(define (read-string-aux input-stream str)
    (let ((c (read-char input-stream)))
      (cond ((eof-object? c)
             (error "reading terminated before string ended"))
            ((equal? #\\ c)
             (str (read-char input-stream))
             (read-string-aux input-stream str))
            ((equal? #\" c)
             (list->string (str)))
            (else
             (str c)
             (read-string-aux input-stream str)))))

(define (read-string input-stream)
  (read-char input-stream) ;; we assume this is #\"
  (read-string-aux input-stream (collector)))

(define (read-until-end-of-line input-stream)
  (if (equal? #\newline (read-char input-stream))
      #f
      (read-until-end-of-line input-stream)))

(define (read-until-whitespace-aux b input-stream)
  (let ((p (peek-char input-stream)))
    (if (whitespace? p)
        b
        (cons (read-char input-stream) b))))

(define (read-until-whitespace input-stream)
  (read-until-whitespace-aux '() input-stream))

(define (finish-reading-char input-stream)
  (let ((code (read-until-whitespace input-stream)))
     (if (= (length code) 1)
         (car code)
         (let ((ctag (list->string code)))
           (cond
            ((equal? ctag "space")  #\space)
            ((equal? ctag "newline") #\newline))))))

(define (scm-read get-line input-stream)
  (skip-whitespace input-stream)
  (let ((class (classify (peek-char input-stream))))
  (cond
    ((equal? 'whitespace class)
     (read-char input-stream)
     (scm-read get-line input-stream))

    ((equal? 'symbolic class) (read-symbol input-stream))
    ((equal? 'string-quote class) (read-string input-stream))
    ((equal? 'lisp-quote class)
     (read-char input-stream)
     (list 'quote (scm-read get-line input-stream)))

    ((equal? 'quasi-quote class)
     (read-char input-stream)
     (list 'quasiquote (scm-read get-line input-stream)))

    ((equal? 'unquote class)
     (read-char input-stream)
     (list 'unquote (scm-read get-line input-stream)))

    ((equal? 'open class)
     (read-char input-stream)
     (scm-read* (collector) get-line input-stream))

    ((equal? 'comment class)
     (read-until-end-of-line input-stream)
     (scm-read get-line input-stream))

    ((equal? 'hash class)
     (read-char input-stream)
     (let ((c (read-char input-stream)))
     (cond
       ((equal? c #\f) #f)
       ((equal? c #\t) #t)
       ((equal? c #\\) (finish-reading-char input-stream))
       (else (error "unknown hash code")))))
    (else (error (string-append "unknown symbol at line " (number->string (get-line))))))))

(define (scm-read* sexps get-line input-stream)
  (skip-whitespace input-stream)
  (if (or (eof-object? (peek-char input-stream))
          (equal? #\) (peek-char input-stream)))
      (begin
        (read-char input-stream)
        (sexps))
      (begin
        (skip-whitespace input-stream)
        (if (equal? 'dot (classify (peek-char input-stream)))
            (begin (read-char input-stream)
                   (let ((result (append (sexps) (scm-read get-line input-stream))))
                     (skip-whitespace input-stream)
                     (if (or (eof-object? (peek-char input-stream))
                             (equal? #\) (peek-char input-stream)))
                         (read-char input-stream)
                         (error "stuff after dot"))
                     result))
            (begin (sexps (scm-read get-line input-stream))
                   (scm-read* sexps get-line input-stream))))))

(define eof-object (gensym "eof"))

(define (eof-object? o)
  (eq? eof-object o))

(define (port-eof? port)
  (= (- (string-length (caddr port)) (car port)) 0))

(define (peek-char port)
  (if (port-eof? port)
      eof-object
      (string-ref (caddr port) 0)))

(define (read-char port)
  (if (port-eof? port)
      eof-object
      (let ((c (string-ref (caddr port) (cell-value (car port)))))
        (if (equal? #\newline c)
            (set-cell! (cadr port) (+ (cell-value (cadr port)) 1))
            #f)
        (set-cell! (car port) (+ 1 (cell-value (car port))))
        c)))


(define (scm-parse-file filename)
  (let* ((sexps (collector))
         (filestr  (file->string filename))
         (line (make-cell 1))
         (get-line (lambda () (cell-value line)))
         (port (list (make-cell 0) line str)))
    (scm-read* sexps get-line port)))

(define (moo)
  (scm-parse-file "stdin"))
