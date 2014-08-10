(define-syntax when
  (syntax-rules ()
    ((when <cond> <body> ...)
     (if <cond> (begin <body> ...) (values)))))
