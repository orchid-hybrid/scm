(define (moo)
  (map display (map desugar (scm-parse-file "stdin"))))
