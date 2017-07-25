# lec 1
Structure and Interpretation of Computer Programs
_in LISP_

~~Computer~~  ~~Science~~
-> (Procedure/Process) (Art/Engineering)


Primatives -> combination -> abstraction

define LISP

>		 	->
>  	eval			apply
>		 	<-

examples:


```
(+ 5 4)
>> 9
```
```
(+ 5 (* 3 2) 8)
>> 19
```
```
(define A (* 8 3))
>> A = 24
```
```
(define (square x) (* x x))
```
```
(square 5)
>> 25
```
```
(define (average x y)
	( /
		(+ x y)
		2
	)
)

average 1 3
>> 2
```
```
(define
	(abs x)
	(if (< x 0)
		(neg x)
		x
	)
)
(abs -9)
>> 9
```


example find square root

```
; sqrt x -> y such that square y = x
; this is declarative knowledge
(define (sqrt x)
	(
		(if square())
	)
)
```
