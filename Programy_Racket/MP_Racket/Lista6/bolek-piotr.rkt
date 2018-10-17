#lang racket

(define (const? t)
  (number? t))

(define (binop? t)
  (and (list? t)
       (= (length t) 3)
       (member (car t) '(+ - * /))))

(define (binop-op e)
  (car e))

(define (binop-left e)
  (cadr e))

(define (binop-right e)
  (caddr e))

(define (binop-cons op l r)
  (list op l r))

(define (op->proc op)
  (cond [(eq? op '+) +]
        [(eq? op '*) *]
        [(eq? op '-) -]
        [(eq? op '/) /]))

(define (let-def? t)
  (and (list? t)
       (= (length t) 2)
       (symbol? (car t))))

(define (let-def-var e)
  (car e))

(define (let-def-expr e)
  (cadr e))

(define (let-def-cons x e)
  (list x e))

(define (let? t)
  (and (list? t)
       (= (length t) 3)
       (eq? (car t) 'let)
       (let-def? (cadr t))))

(define (let-def e)
  (cadr e))

(define (let-expr e)
  (caddr e))

(define (let-cons def e)
  (list 'let def e))

(define (var? t)
  (symbol? t))

(define (var-var e)
  e)

(define (var-cons x)
  x)

(define (hole? t)
  (eq? t 'hole))

(define (arith/let/holes? t)
  (or (hole? t)
      (const? t)
      (and (binop? t)
           (arith/let/holes? (binop-left  t))
           (arith/let/holes? (binop-right t)))
      (and (let? t)
           (arith/let/holes? (let-expr t))
           (arith/let/holes? (let-def-expr (let-def t))))
      (var? t)))

(define (num-of-holes t)
  (cond [(hole? t) 1]
        [(const? t) 0]
        [(binop? t)
         (+ (num-of-holes (binop-left  t))
            (num-of-holes (binop-right t)))]
        [(let? t)
         (+ (num-of-holes (let-expr t))
            (num-of-holes (let-def-expr (let-def t))))]
        [(var? t) 0]))

(define (arith/let/hole-expr? t)
  (and (arith/let/holes? t)
       (= (num-of-holes t) 1)))

(define (hole-context e)
  (define (hole-context-helper e wynik)
    (if (or (hole? e) (null? e))
        wynik
        (cond [(binop? e)
               (remove-duplicates (append (hole-context-helper (binop-left e) wynik))
                       (hole-context-helper (binop-right e) wynik))]
              [(let? e)
               (remove-duplicates (append
                                   (hole-context-helper (let-def-var (let-def e)) wynik)
                                   (hole-context-helper (let-def-expr (let-def e)) wynik)
                                   (hole-context-helper (let-expr e) wynik)))]
                                                  
              [(symbol? e)
               (if (ormap (lambda (y) (eq? e y)) wynik)
                   wynik
                   (append wynik (list e)))]
              [else wynik])))
  
  (if (arith/let/hole-expr? e)
      (hole-context-helper e null)
      #f)
  )

(define (test)
  (define (eq-lists? a b)
    (if (or (null? a) (null? b))
            #f
            (if (and (list? a) (list? b))
                (if (= (length a) (length b))
                    (if (eq? (car a) (car b))
                        (eq-lists? (cdr a) (cdr b))
                        #f)
                    #f)
                #f)))
  (and
   (eq-lists? (sort (hole-context '(+ 3 hole)) <) '())
   (eq-lists? (sort (hole-context '(let (x 3) (let (y 7) (+ x hole)))) <) (sort '(x y)))
   (eq-lists? (sort (hole-context '(let (x 3) (let (y hole) (+ x 3)))) <) '(x))
   (eq-lists? (sort (hole-context '(let (x hole) (let (y 7) (+ x 3)))) <) '())
   (eq-lists? (sort (hole-context '(let (piesek 1)
                                     (let (kotek 7)
                                       (let (piesek 9)
                                         (let chomik 5)
                                         hole)))) <)
              (sort '(chomik piesek kotek) <))
   (eq-lists? (sort (hole-context '(+ (let (x 4) 5) hole)) <) '()))
  )

(hole-context '(+ 3 hole))
(hole-context '(let (x 3) (let (y 7) (+ x hole))))
( hole-context '( let ( x 3) ( let ( y hole ) (+ x 3))))
( hole-context '( let ( x hole ) ( let ( y 7) (+ x 3) ) ) )
( hole-context '( let ( piesek 1)
( let ( kotek 7)
( let ( piesek 9)
( let ( chomik 5)
hole ) ) ) ) )
( hole-context '(+ ( let ( x 4) 5) hole ) )
(test)
