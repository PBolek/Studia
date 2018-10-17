#lang racket

(define (dist x y)
  (abs (- x y)))

(define (average x y)
  (/ (+ (/ x (* y y)) (* 2 y)) 3))

(define (cube x)
  (* x x x))

(define (cube-root x)
  (define (improve approx)
    (average x approx))
  (define (good-enough? approx)
    (< (dist x (cube approx)) 0.0001))
  (define (iter approx)
    (cond
      [(good-enough? approx) approx]
      [else                  (iter (improve approx))]))
  
  (iter 1.0))
;; testy
(cube-root 8)
(cube-root 2)
(cube-root -1)
(cube-root 1)
(cube-root 27)
(cube-root -8)
(cube-root 74088)
(cube-root 0)