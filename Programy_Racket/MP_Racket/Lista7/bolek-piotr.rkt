; Piotr Bolek (Indeks: 301305)
; Współpracowałem z:
; Paweł Talar (Indeks: 300644)
; Patryk Pęczak (Indeks: 299996)

#lang racket
 
;; expressions
 
(define (const? t)
  (number? t))
 
(define (op? t)
  (and (list? t)
       (member (car t) '(+ - * /))))
 
(define (op-op e)
  (car e))
 
(define (op-args e)
  (cdr e))
 
(define (op-cons op args)
  (cons op args))
 
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
 
(define (arith/let-expr? t)
  (or (const? t)
      (and (op? t)
           (andmap arith/let-expr? (op-args t)))
      (and (let? t)
           (arith/let-expr? (let-expr t))
           (arith/let-expr? (let-def-expr (let-def t))))
      (var? t)))
 
;; let-lifted expressions
 
(define (arith-expr? t)
  (or (const? t)
      (and (op? t)
           (andmap arith-expr? (op-args t)))
      (var? t)))
 
(define (let-lifted-expr? t)
  (or (and (let? t)
           (let-lifted-expr? (let-expr t))
           (arith-expr? (let-def-expr (let-def t))))
      (arith-expr? t)))
 
;; generating a symbol using a counter
 
(define (number->symbol i)
  (string->symbol (string-append "x" (number->string i))))
 
;; environments (could be useful for something)
 
(define empty-env
  null)
 
(define (add-to-env x v env)
  (cons (list x v) env))
 
(define (find-in-env x env)
  (cond [(null? env) (error "undefined variable" x)]
        [(eq? x (caar env)) (cadar env)]
        [else (find-in-env x (cdr env))]))
 
;; the let-lift procedure
 
(define (get-max res)
  (first res))
 
(define (get-list res)
  (second res))
 
(define (get-expr res)
  (third res))
 
(define (let-lift e)
  (define (let-lift-result f env arguments acc operator)
    (if (null? arguments)
        (list (get-max acc)
              (get-list acc)
              (op-cons operator (get-expr acc)))
    (let ([arg-res (f (car arguments) env (get-max acc))])
      (let-lift-result f env (cdr arguments)
                   (list (get-max arg-res)
                         (append (get-list arg-res) (get-list acc))
                         (append (get-expr acc) (list (get-expr arg-res))))
                   operator))))
 
  (define (let-lift-help e env number)
    (cond [(const? e) (list number null e)]
          [(var? e) (list (+ 1 number) null (find-in-env e env))]
          [(let? e)
           (let* ([def-val (let-lift-help (let-def-expr (let-def e))
                                          env number)]
                 [expr-let (let-lift-help (let-expr e)
                                      (add-to-env (let-def-var (let-def e))
                                                  (number->symbol (get-max def-val)) env)
                                      (+ (get-max def-val) 1))]
                 [new-name (number->symbol (get-max def-val))])
             (list (get-max expr-let)
                   (append (get-list def-val)
                           (get-list expr-let)
                           (list (cons new-name (get-expr def-val))))
                   (get-expr expr-let)))]
          [(op? e) (let-lift-result let-lift-help
                                    env
                                    (op-args e)
                                    (list number null null)
                                    (op-op e))]))
  (define (parse x)
    (if (null? (get-list x))
        (get-expr x)
        (let-cons (let-def-cons (caar (get-list x)) (cdr (car (get-list x))))
                  (parse (list (get-max x) (cdr (get-list x)) (get-expr x))))))
  (parse (let-lift-help e empty-env 0)))

(define test1 '(+ 1 2 3))
(define test2 '(let (a 15) (let (a 2) (+ a a))))
(define test3 '(let (a 15) (let (b 2) (+ a b))))
(define test4 '(let (x (let (y 4) y)) (+ x 3)))
(define test5 '(let (x (- 2 (let (z 3) z))) (+ x 2))) 

(define (test list)
  (let-lifted-expr? (let-lift list)))

test1
(let-lift test1)
(test (let-lift test1))
test2
(let-lift test2)
(test (let-lift test2))
test3
(let-lift test3)
(test (let-lift test3))
test4
(let-lift test4)
(test (let-lift test4))
test5
(let-lift test5)
(test (let-lift test5))