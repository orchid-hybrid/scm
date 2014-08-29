

(define (emit-c term)
  (begin
    (display "emitting-c")
    (cond ((null? term)
           (display "scmalloc((scm){ .t = scm_type_null })"))
          ((number? term)
           (display (string-append "scmalloc((scm){ .t = scm_type_number, .v.n = "
                                   (string-append (number->string term) " })"))))
          ((boolean? term)
           (display (if term
                        "scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 })"
                        "scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 })")))
          ((string? term)
           (display "scm_string")
           (display "(")
           (display term)
           (display ")"))
          ((char? term)
           (display "scm_char")
           (display "(")
           (display (char->string term))
           (display ")"))
          ((symbol? term)
           (display term))
          ((and (list? term)
                (not (null? term))
                (= (length term) 2)
                (equal? (car term) 'quote))
           (if (symbol? (cadr term))
               (begin (display "scm_make_symbol(")
                      (display (symbol->string (cadr term)))
                      (display ")"))
               (error "Dont know how to quote that ")))
          ((and (list? term)
                (not (null? term)))
           (display (car term))
           (display (cdr term))
           (newline))
          (else (error "emit-c!")))))

(define (moo)
  (begin
    (display (emit-c 'foo)) (newline)
    ))
