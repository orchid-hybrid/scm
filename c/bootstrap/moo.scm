(define (moo)
  (compile-c-definitions (map desugar (scm-parse-file "stdin"))))
