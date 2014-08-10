
;; lambda lifting removes free variables where it can by turning
;;
;; ((lambda (vars ...) body ...) args ...)
;;
;; into
;; 
;; ((lambda (vars ... free-vars ...) body ...) args ... free-vars ...)

;;(define (special-form? head)
;;  (member head '(quote lambda begin)))

(define (free-vars bound-vars term)
  ;; if the car is a special form process that form specially
  ;; else combine take all the free vars from each part
  ;;
  ;; hack: include quote lambda begin symbols in the bound-vars part
  ;;
  (cond ((symbol? term)
         (if (member? term bound-vars)
             '()
             (list term)))
        ((not (list? term)) ;; strings etc.
         '())
        ;;((special-form? (car term))
        ;; (free-vars 
        (else (apply append (map (lambda (term) (free-vars bound-vars term)) term)))))


