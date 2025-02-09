;;Piotr Bolek lista 12

#lang racket

;; sygnatura: grafy
(define-signature graph^
  ((contracted
    [graph        (-> list? (listof edge?) graph?)]
    [graph?       (-> any/c boolean?)]
    [graph-nodes  (-> graph? list?)]
    [graph-edges  (-> graph? (listof edge?))]
    [edge         (-> any/c any/c edge?)]
    [edge?        (-> any/c boolean?)]
    [edge-start   (-> edge? any/c)]
    [edge-end     (-> edge? any/c)]
    [has-node?    (-> graph? any/c boolean?)]
    [outnodes     (-> graph? any/c list?)]
    [remove-node  (-> graph? any/c graph?)]
    )))

;; prosta implementacja grafów
(define-unit simple-graph@
  (import)
  (export graph^)

  (define (graph? g)
    (and (list? g)
         (eq? (length g) 3)
         (eq? (car g) 'graph)))

  (define (edge? e)
    (and (list? e)
         (eq? (length e) 3)
         (eq? (car e) 'edge)))

  (define (graph-nodes g) (cadr g))

  (define (graph-edges g) (caddr g))

  (define (graph n e) (list 'graph n e))

  (define (edge n1 n2) (list 'edge n1 n2))

  (define (edge-start e) (cadr e))

  (define (edge-end e) (caddr e))

  (define (has-node? g n) (not (not (member n (graph-nodes g)))))
  
  (define (outnodes g n)
    (filter-map
     (lambda (e)
       (and (eq? (edge-start e) n)
            (edge-end e)))
     (graph-edges g)))

  (define (remove-node g n)
    (graph
     (remove n (graph-nodes g))
     (filter
      (lambda (e)
        (not (eq? (edge-start e) n)))
      (graph-edges g)))))

;; sygnatura dla struktury danych
(define-signature bag^
  ((contracted
    [bag?       (-> any/c boolean?)]
    [bag-empty? (-> bag? boolean?)]
    [empty-bag  (and/c bag? bag-empty?)]
    [bag-insert (-> bag? any/c (and/c bag? (not/c bag-empty?)))]
    [bag-peek   (-> (and/c bag? (not/c bag-empty?)) any/c)]
    [bag-remove (-> (and/c bag? (not/c bag-empty?)) bag?)])))

;; struktura danych - stos
(define-unit bag-stack@
  (import)
  (export bag^)
;; TODO: zaimplementuj stos
  (define (bag? x)
    (list? x))
  (define (bag-empty? x)
    (null? x))
  (define empty-bag
    '())
  (define (bag-insert x y)
    (cons y x))
  (define (bag-peek x)
    (car x))
  (define (bag-remove x)
    (cdr x))
)

;; struktura danych - kolejka FIFO
;; do zaimplementowania przez studentów
(define-unit bag-fifo@
  (import)
  (export bag^)
;; TODO: zaimplementuj kolejkę
  (define (bag? x)
    (and (and (list? (car x)) (list? (cdr x))) (pair? x)))
  (define (bag-empty? x)
    (and (null? (car x)) (null? (cdr x))))
  (define empty-bag
    (cons '() '()))
  (define (bag-insert x y)
    (if (null? (cdr x))
        (cons '() (reverse (cons y (car x))))
        (cons (cons y (car x)) (cdr x))))        
  (define (bag-peek x)
    (car (cdr x)))
  (define (bag-remove x)
    (if (null? (cddr x))
        (cons '() (reverse (car x)))
        (cons (car x) (cddr x))))
)

;; sygnatura dla przeszukiwania grafu
(define-signature graph-search^
  (search))

;; implementacja przeszukiwania grafu
;; uzależniona od implementacji grafu i struktury danych
(define-unit/contract graph-search@
  (import bag^ graph^)
  (export (graph-search^
           [search (-> graph? any/c (listof any/c))]))
  (define (search g n)
    (define (it g b l)
      (cond
        [(bag-empty? b) (reverse l)]
        [(has-node? g (bag-peek b))
         (it (remove-node g (bag-peek b))
             (foldl
              (lambda (n1 b1) (bag-insert b1 n1))
              (bag-remove b)
              (outnodes g (bag-peek b)))
             (cons (bag-peek b) l))]
        [else (it g (bag-remove b) l)]))
    (it g (bag-insert empty-bag n) '()))
  )

;; otwarcie komponentu grafu
(define-values/invoke-unit/infer simple-graph@)

;; graf testowy
(define test-graph
  (graph
   (list 1 2 3 4)
   (list (edge 1 3)
         (edge 1 2)
         (edge 2 4))))

(define test-graph2
  (graph
   (list 1 2 3 4)
   (list (edge 1 2)
         (edge 2 3)
         (edge 2 4))))

(define test-graph3
  (graph
   (list 1 2 3 7 41 50)
   (list (edge 1 2)
         (edge 1 3)
         (edge 3 50)
         (edge 2 7)
         (edge 2 41))))
;; TODO: napisz inne testowe grafy!

;; otwarcie komponentu stosu
(define-values/invoke-unit/infer bag-stack@)
;; opcja 2: otwarcie komponentu kolejki
;(define-values/invoke-unit/infer bag-fifo@)

;; testy w Quickchecku
(require quickcheck)

;; test przykładowy: jeśli do pustej struktury dodamy element
;; i od razu go usuniemy, wynikowa struktura jest pusta
(quickcheck
 (property ([s arbitrary-symbol])
           (bag-empty? (bag-remove (bag-insert empty-bag s)))))
;; TODO: napisz inne własności do sprawdzenia!
;; jeśli jakaś własność dotyczy tylko stosu lub tylko kolejki,
;; wykomentuj ją i opisz to w komentarzu powyżej własności

;; otwarcie komponentu przeszukiwania
(define-values/invoke-unit/infer graph-search@)

;; uruchomienie przeszukiwania na przykładowym grafie
(search test-graph 1)
;; TODO: uruchom przeszukiwanie na swoich przykładowych grafach!
(search test-graph2 1)
(search test-graph3 1)

(quickcheck
 (property ([s arbitrary-symbol])
           (eq? (bag-peek (bag-insert empty-bag s)) s)))
#|
;;test dla kolejki
(quickcheck
 (property ([s arbitrary-symbol]
            [t arbitrary-symbol])
           (eq? (bag-peek (bag-insert (bag-insert empty-bag s) t)) s)))
|#

;;test dla stosu
(quickcheck
 (property ([s arbitrary-symbol]
           [t arbitrary-symbol])
           (eq? (bag-peek (bag-insert (bag-insert empty-bag s) t)) t)))

           