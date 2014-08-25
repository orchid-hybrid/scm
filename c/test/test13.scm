(define (eq-test)
  (and (= 1 1) (not (= 1 2))))

(define (gt-test)
  (and (> 2 1) (not (> 1 2))))

(define (lt-test)
  (and (< 1 2) (not (< 2 1))))

(define (gte-test)
  (and (>= 1 1) (>= 2 1) (not (>= 1 2))))

(define (lte-test)
  (and (<= 1 1) (<= 1 2) (not (<= 2 1))))

(define (moo)
  (if (and (eq-test) (gt-test) (gte-test) (lt-test) (lte-test))
      (print "comparisons pass")
      (print "comparisons fail")))
