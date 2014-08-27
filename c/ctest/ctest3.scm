(define (mangle s)
  (let ((down (lambda (khar)
                (cond 
                 ((equal? khar #\-) (list #\_))
                 ((equal? khar #\?) (list #\_ #\q #\u #\e #\s #\t #\i #\o #\n))
                 ((equal? khar #\!) (list #\_ #\b #\a #\n #\g))
                 ((equal? khar #\=) (list #\_ #\n #\u #\m #\e #\q))
                 ((equal? khar #\<) (list #\_ #\l #\t))
                 ((equal? khar #\>) (list #\_ #\g #\t))
                 ((equal? khar #\*) (list #\_ #\s #\t #\a #\r))
                 (else (list khar))))))
    (let ((mangled (map down (string->list (symbol->string s)))))
      (list->string (foldl append '() mangled)))))

(define (moo)
  (display (foldl append '() '((a b c) (d e) (f g h))))
  (display (list->string (list #\a #\b #\c)))
  )
