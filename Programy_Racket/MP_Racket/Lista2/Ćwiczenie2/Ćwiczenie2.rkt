#lang racket

(define ((compose procedure1 procedure2) x)
  (procedure1 (procedure2 x)))


(define (inc i)
  (+ i 1))

(define (square x)
  (* x x))