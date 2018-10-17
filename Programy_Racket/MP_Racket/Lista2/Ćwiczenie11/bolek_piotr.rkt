#lang racket

(define (dist x y)
  (abs (- x y)))

(define (close-enough? x y)
  (< (dist x y) 0.00001))

(define (compose f g)
  (lambda (x) (f (g x))))

(define (identity x)
  x)

(define (inc x)
  (+ x 1))

(define (square x)
  (* x x))

(define (dec x)
  (- x 1))

(define (repeated p n)
  (if (= n 1)
      p
      (compose p (repeated p (dec n)))))

(define (fixed-point f x0)
  (let ((x1 (f x0)))
    (if (close-enough? x0 x1)
        x0
        (fixed-point f x1))))

(define (average x y)
  (/ (+ x y) 2.0))

(define (average-damp f)
  (lambda (x) (average x (f x))))

(define (log_n k n)
  (/ (log n) (log k)))

(define (nth_root x n)
  (fixed-point (repeated (average-damp (lambda (y) (/ x (expt y (- n 1))))) (floor (log_n 2 n))) 1.0))

(nth_root 16.0 4.0)
(nth_root 27.0 3.0)
(nth_root 4.0 2.0)
(nth_root 256.0 8.0)
(nth_root 28561.0 4.0)