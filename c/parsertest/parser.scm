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



;; This implements gensym, a fresh name generator
;; it stores all the symbols it's previously created
;; and makes sure it only hands out something never
;; seen before

(define (member s l)
  (if (null? l)
      #f
      (or (equal? s (car l))
          (member s (cdr l)))))

(define symbol-table (make-cell '()))

(define (symbol-add s)
  ;; Add the symbol s to the symbol-table
  ;; unless it's already in there.
  ;; Returns a #t if the symbol is fresh and
  ;; had to be added, #f if it was already in
  ;; there.
  (if (member s (cell-value symbol-table))
      #f
      (begin
        (set-cell! symbol-table (cons s (cell-value symbol-table)))
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
             ((cdr str) (read-char input-stream))
             (read-string-aux input-stream str))
            ((equal? #\" c)
             (list->string ((car str))))
            (else
             ((cdr str) c)
             (read-string-aux input-stream str)))))

(define (read-string input-stream)
  (read-char input-stream) ;; we assume this is #\"
  (read-string-aux input-stream (collector)))

(define (read-until-end-of-line input-stream)
  (if (equal? #\newline (read-char input-stream))
      #f
      (read-until-end-of-line input-stream)))

(define (assert-code codes input-stream)
  (if (null? codes)
      #f
      (if (equal? (car codes)
                  (read-char input-stream))
          (assert-code (cdr codes) input-stream)
          (error "unknown character code"))))

(define (finish-reading-char input-stream)
  (let ((first-char (read-char input-stream)))
    (cond ((or (whitespace? (peek-char input-stream))
               (equal? #\) (peek-char input-stream)))
           first-char)
          ((equal? #\s first-char)
           (assert-code (list #\p #\a #\c #\e) input-stream)
           #\space)
          ((equal? #\n first-char)
           (assert-code (list #\e #\w #\l #\i #\n #\e) input-stream)
           #\newline)
          (else (error "unknown character code")))))


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

(define eof-object 1)

(define (eof-object? o)
  (number? o))

(define (peek-char port)
  (let ((c (peek-char0)))
    (if (number? c)
        eof-object
        c)))

(define (read-char port)
  (let ((c (read-char0)))
    (if (number? c)
        eof-object
        (begin 
          (if (equal? #\newline c)
              (set-cell! (cadr port) (+ (cell-value (cadr port)) 1))
              #f)
          (set-cell! (car port) (+ 1 (cell-value (car port))))
          c))))

(define (open-input-file x) x)

(define (wrap-port-with-line-tracking p)
  (let* ((line (make-cell 1))
         (get-line (lambda () (cell-value line))))
    (cons get-line
          (list (make-cell 0) line))))

(define (scm-parse-file filename)
  (let ((sexps (collector))
        (line-port (wrap-port-with-line-tracking (open-input-file filename))))
    (scm-read* sexps (car line-port) (cdr line-port))))

(define (moo)
  (scm-parse-file "asd"))
