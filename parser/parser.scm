;; depends on utility/list.scm

(define (collector) ;; TODO switch over to the collector in utility
  ;; collect elements into a list and ask for its value
  ;; 
  ;; (let ((c (collector)))
  ;;    (c 'a) (c 'b) (c))
  (let ((list '())
        (last-cell #f))
    (lambda args
      (if (null? args)
          list
          (if last-cell
              (begin
                (set-cdr! last-cell (cons (car args) '()))
                (set! last-cell (cdr last-cell)))
              (begin
                (set! list (cons (car args) '()))
                (set! last-cell list)))))))

(define (whitespace? char)
  (or (equal? char #\space)
      (equal? char #\newline)))

(define (symbolic? char)
  (or (char-alphabetic? char)
      (char-numeric? char)
      (equal? #\= char)
      (equal? #\* char)
      (equal? #\- char)
      (equal? #\+ char)
      (equal? #\. char)
      (equal? #\? char)
      (equal? #\! char)
      (equal? #\< char)
      (equal? #\> char)))

(define (skip-whitespace stream)
  (if (whitespace? (peek-char stream))
      (begin (read-char stream)
             (skip-whitespace stream))
      #f))

(define (classify char)
  (cond ((eof-object? char) 'eof)
        ((whitespace? char) 'whitespace)
        ((equal? char #\.) 'dot)
        ((symbolic? char) 'symbolic)
        ((equal? char #\") 'string-quote)
        ((equal? char #\') 'lisp-quote)
        ((equal? char #\`) 'quasi-quote)
        ((equal? char #\,) 'unquote)
        ((equal? char #\() 'open)
        ((equal? char #\;) 'comment)
        ((equal? char #\#) 'hash)
        (else 'unknown)))

(define (read-symbol input-stream)
  (let ((create-symbol (lambda (chars)
                         (if (all char-numeric? chars)
                             (string->number (list->string chars))
                             (string->symbol (list->string chars))))))
    (let loop ((sym (collector)))
      (if (symbolic? (peek-char input-stream))
          (begin
            (sym (read-char input-stream))
            (loop sym))
          (create-symbol (sym))))))

(define (read-string input-stream)
  (read-char input-stream) ;; we assume this is #\"
  (let loop ((str (collector)))
    (let ((char (read-char input-stream)))
      (cond ((eof-object? char)
             (error "reading terminated before string ended"))
            ((equal? #\\ char)
             (str (read-char input-stream))
             (loop str))
            ((equal? #\" char)
             (list->string (str)))
            (else
             (str char)
             (loop str))))))

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
  (let ((code (read-until-whitespace input-stream))
        (string->char (lambda (s) (string-ref s 0))))
     (if (= (length code) 1)
         (car code)
         (case (foldr string "" code)
           (("space")  #\space)
           (("newline")  #\newline)))))

;; (define (finish-reading-char input-stream)
;;   (define (assert-code codes)
;;     (if (null? codes)
;;         #f
;;         (if (equal? (car codes)
;;                     (read-char input-stream))
;;             (assert-code (cdr codes))
;;             (error "unknown character code"))))
;;   (let ((first-char (read-char input-stream)))
;;     (cond ((or (whitespace? (peek-char input-stream))
;;                (equal? #\) (peek-char input-stream)))
;;            first-char)
;;           ((equal? #\s first-char)
;;            (assert-code '(#\p #\a #\c #\e))
;;            #\space)
;;           ((equal? #\n first-char)
;;            (assert-code '(#\e #\w #\l #\i #\n #\e))
;;            #\newline)
;;           (else (error "unknown character code")))))

(define (scm-read get-line input-stream)
  (skip-whitespace input-stream)
  (case (classify (peek-char input-stream))
    ((whitespace) (read-char input-stream)
                  (scm-read get-line input-stream))
    ((symbolic) (read-symbol input-stream))
    ((string-quote) (read-string input-stream))
    ((lisp-quote) (read-char input-stream)
                  (list 'quote (scm-read get-line input-stream)))
    ((quasi-quote) (read-char input-stream)
                   (list 'quasiquote (scm-read get-line input-stream)))
    ((unquote) (read-char input-stream)
               (list 'unquote (scm-read get-line input-stream)))
    ((open) (read-char input-stream)
            (scm-read* (collector) get-line input-stream))
    ((comment) (read-until-end-of-line input-stream)
               (scm-read get-line input-stream))
    ((hash) (read-char input-stream)
            (case (read-char input-stream)
              ((#\f) #f)
              ((#\t) #t)
              ((#\\) (finish-reading-char input-stream))
              (else (error "unknown hash code"))))
    (else (error (string-append "unknown symbol at line " (number->string (get-line)))))))

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

(define (wrap-port-with-line-tracking port)
  (let ((line 1))
    (define (read-char*)
      (let ((c (read-char port)))
        (if (equal? #\newline c)
            (set! line (+ line 1))
            #f)
        c))
    (define (char-ready?*)
      (char-ready port))
    (define (close*)
      (close port))
    (define (peek-char*)
      (peek-char port))
    (values (lambda () line)
            (make-input-port read-char* char-ready?* close* peek-char*))))

(define (scm-parse-file filename)
  (let ((sexps (collector)))
    (call-with-values
        (lambda ()
          (wrap-port-with-line-tracking (open-input-file filename)))
      (lambda (get-line port)
        (scm-read* sexps get-line port)))))
