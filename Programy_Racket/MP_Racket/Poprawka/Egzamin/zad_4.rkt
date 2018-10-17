#lang racket
(define (merge xs ys)
  (define (merge-help xs ys acc)
    (cond [[null? xs] (cons acc ys)]
          [[null? ys] (cons acc xs)]
          [else (if (>= (car xs) (car ys))
                    (merge-help xs (cdr ys) (cons acc (car ys)))
                    (merge-help (cdr xs) ys (cons acc (car xs))))]))
  (flatten (merge-help xs ys null)))

(merge '(1 2 3) '(2 3 4))