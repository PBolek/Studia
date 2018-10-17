#lang racket

(define (close-enough? A B)
  (< (abs (- A B)) 0.000001))

(define (inc a)
  (+ a 1))

(define (wzor A-1 A-2 D N)
  (+ (* D A-1) (* N A-2)))

(define (square x)
  (* x x))

;;przykladowy test opiera się na ciągu opisanym podczas opisu ułamków łańcuchowych na liście 2
(define (licznik_test1 x) x) ;;ciag licznikow ulamka lancuchowego
(define (mianownik_test1 x) x) ;;ciag mianownikow ulamka lancuchowego

(define (ulamek_lancuchowy A A-1 B B-1 D N)
  (cond
    ( (close-enough? (/ (wzor A A-1 D N) (wzor B B-1 D N)) (/ A B)) (/ A B))
    ( else (ulamek_lancuchowy (wzor A A-1 D N) A (wzor B B-1 D N) B D N))))

(ulamek_lancuchowy 0 1 1 0 (licznik_test1 1) (mianownik_test1 1))
(ulamek_lancuchowy 0 1 1 0 (licznik_test1 10) (mianownik_test1 10))
(ulamek_lancuchowy 0 1 1 0 (licznik_test1 123) (mianownik_test1 123))
      
      
       