#lang racket

(require racklog)

;; predykat unarny %male reprezentuje zbiór mężczyzn
(define %male
  (%rel ()
        [('adam)]
        [('john)]
        [('joshua)]
        [('mark)]
        [('david)]))

;; predykat unarny %female reprezentuje zbiór kobiet
(define %female
  (%rel ()
        [('eve)]
        [('helen)]
        [('ivonne)]
        [('anna)]))

;; predykat binarny %parent reprezentuje relację bycia rodzicem
(define %parent
  (%rel ()
        [('adam 'helen)]
        [('adam 'ivonne)]
        [('adam 'anna)]
        [('eve 'helen)]
        [('eve 'ivonne)]
        [('eve 'anna)]
        [('john 'joshua)]
        [('helen 'joshua)]
        [('ivonne 'david)]
        [('mark 'david)]))

;; predykat binarny %sibling reprezentuje relację bycia rodzeństwem
(define %sibling
  (%rel (a b c)
        [(a b)
         (%parent c a)
         (%parent c b)]))

;; predykat binarny %sister reprezentuje relację bycia siostrą
(define %sister
  (%rel (a b)
        [(a b)
         (%sibling a b)
         (%female a)]))

;; predykat binarny %ancestor reprezentuje relację bycia przodkiem
(define %ancestor
  (%rel (a b c)
        [(a b)
         (%parent a b)]
        [(a b)
         (%parent a c)
         (%ancestor c b)]))

;;Ćwiczenie 1

(define %is_mother
  (%rel (x c)
        [(x)
         (%parent x c)
         (%female x)]))

(define %is_father
  (%rel (x c)
        [(x)
         (%parent x c)
         (%male x)]))

(require racklog)

(define %my-append
  (%rel (x xs ys zs)
        [(null ys ys)]
        [((cons x xs) ys (cons x zs))
         (%my-append xs ys zs)]))

(define %my-member
  (%rel (x xs y)
        [(x (cons x xs))]
        [(y (cons x xs))
         (%my-member y xs)]))

(define %select
  (%rel (x xs y ys)
        [(x (cons x xs) xs)]
        [(y (cons x xs) (cons x ys))
         (%select y xs ys)]))

;; prosta rekurencyjna definicja
(define %simple-length
  (%rel (x xs n m)
        [(null 0)]
        [((cons x xs) n)
         (%simple-length xs m)
         (%is n (+ m 1))]))

;; test w trybie +- (działa)
(%find-all (a) (%simple-length (list 1 2) a))
;; test w trybie ++ (działa)
(%find-all () (%simple-length (list 1 2) 2))
;; test w trybie -+ (1 odpowiedź, pętli się)
(%which (xs) (%simple-length xs 2))
;; test w trybie -- (nieskończona liczba odpowiedzi)
(%which (xs a) (%simple-length xs a))

;; definicja zakładająca, że długość jest znana
(define %gen-length
  (%rel (x xs n m)
        [(null 0) !]
        [((cons x xs) n)
         (%is m (- n 1))
         (%gen-length xs m)]))
;; test w trybie ++ (działa)
(%find-all () (%gen-length (list 1 2) 2))
;; test w trybie -+ (działa)
(%find-all (xs) (%gen-length xs 2))


;;Ćwiczenie 3

;;(%which (a b) (%append a a b))

;;(%which (x) (%select x '(1 2 3 4) '(1 2 4)))

;;(%which (x y) (%append x y (list 1 2)))

;;Ćwiczenie 6
;;Wersja normalna
(define (sublist? xs ys)
  (or (null? xs)
      (if (= (car xs) (car ys))
          (sublist? (cdr xs) (cdr ys))
          (sublist? xs (cdr ys)))))
;;+/- wersja Racklog
(define %sublist
  (%rel (xs ys x y)
        [(xs ys)
         (%sublist '() ys)
         ((%sublist (cons x xs) (cons x ys))<=(%sublist xs ys))
         ((%sublist (cons x xs) (cons y ys))<=(and (not (= x y)) (%sublist (cons x xs) ys)))]))

;;Ćwiczenie 7
;;+/- wersja Racklog
(define %perm
  (%rel (xs ys)
        [(xs ys)
         (%perm '() '())
         (= (length xs) (length ys))
         (%perm (cdr xs) (%select (car xs) ys))]))
;;Drugie podejscie
#|(define %perm
  (%rel (xs ys)
        [(xs ys)
         (and (%sorted xs sxs) (%sorted ys sys) (=:= sxs sys))]))|#
