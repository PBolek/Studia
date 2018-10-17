#lang racket

(define (make-point x y)
  (cons x y))

(define (point-x x)
  (car x))

(define (point-y x)
  (cdr x))

(define (point? x)
  (pair? x))

(define (make-vect x y)
  (cons x y))

(define (vect? x)
  (and (point? (car x)) (point? (cdr x))))

(define (vect-begin x)
  (car x))

(define (vect-end x)
  (cdr x))

(define (vect-length x)
  (sqrt
   (+
         (-
          (point-x (vect-end x))
          (point-x (vect-begin x)))
         (-
          (point-y (vect-end x))
          (point-y (vect-begin x))))))

(define (vect-scale v k)
  (define w (make-vect
             (vect-begin v)
             (make-point
               (+ 1 (point-x (vect-end v)))
               (+ 1 (point-y (vect-end v))))))
  (if (= (* (vect-length v) k) (vect-lenght w))
      w
      (vect-scale w k)))
  
    