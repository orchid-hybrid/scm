;; csi genvector.scm -e '(moo)' > scm_vector.c

(define (almost-to i n)
  (if (= i n) '()
      (cons i (almost-to (+ 1 i) n))))

(define (for-each-between f comma list)
  (if (null? list) #f
      (if (null? (cdr list))
          (f (car list))
          (begin
            (f (car list))
            (comma)
            (for-each-between f comma (cdr list))))))

(define (gen-vector header?)
  (lambda (i)
    ;; TODO add inclue for scm.h
    (display "scm* scm_vector") (display (number->string i)) (display "(")
    (for-each-between (lambda (i)
                        (display "scm *v") (display i))
                      (lambda ()
                        (display ", "))
                      (almost-to 0 i))
    (if header?
        (begin (display ");") (newline))
        (begin
          (display ") {") (newline)
          (display "  scm **v = gc_alloc(") (display (number->string i)) (display "*sizeof(scm*));") (newline)
          (display "  ")
          (for-each (lambda (i)
                      (display "v[") (display (number->string i)) (display "] = v") (display (number->string i)) (display "; "))
                    (almost-to 0 i))
          (newline)
          (display "  return scalloc((scm){ .t = scm_type_vector, .v.vektor.v = v, .v.vektor.len = ") (display (number->string i)) (display " });") (newline)
          (display "}") (newline)
          (newline)))))

(define (moo)
  (for-each (gen-vector #t) (almost-to 0 128)))
