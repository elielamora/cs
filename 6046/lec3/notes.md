# Mit 6.046 lecture 3
## Divide & Conquer: FFT
Link to video lecture
[here](https://www.youtube.com/watch?v=iTMn0Kt18tg).



## Fast Fourier Transform
###### Lecture summary:

- Divide and Conquer algorithm
- collapsing samples/ roots of unity
- fft, ifft, and poly. mult.

###### Polynomial Representations:
- A(x) = a<sub>0</sub> + a<sub>1</sub> * x + a<sub>2</sub> * x<sup>2</sup> + ... + a<sub>n</sub> x<sup>n</sup>
- array form: a<sub>0</sub>, a<sub>1</sub>,  ... , a<sub>n</sub>
- or ordered pair for sparse polynomial

###### Operations on Polynomials:
1. Evaluation `A(x) -> number`
        O(n^2) with naive sub. and mult.
        O(n) 'dot product'
        O(n) via horner's rule:
                A(x) = a0 + x(a1 + x(a2 + ... ).. )
        * assuming +, /, x, - are O(1)
2. Addition: `A(x) + B(x) = C(x)`
        c_k = a_k + b_k
        O(n)
3. Multiplication:  `A(x) * B(x) = C(x)`
        (a0 + a1x + a2x ...) *
        (b0 + b1x + b2x ...)
        = a0b0 + ... (high school)
        O(n^2)
        ** goal achieve O(nlgn)

###### Other uses for Poly mult.:
- used for convolution of vectors A and reverse (B)
- used for signal processing, gaussian blurs...
- inner product of all possible shifts


###### Polynomial Representations:
1. (A) coeff. vector  <a0, a1, a2,...)
2. (B) roots, P(x) = c(x-r0) * (x-r1) * ... * (x-r(n-1))
3. (C) samples: (x_k, y_k), for k = 0, 1, ... , n-1 for
destinct x


### Poly Algorithms:

Representations (A, B, C)
Operations (1, 2, 3)

|	| A  		|      B 	|      C	|
|---	|---		|---		|---		|
|1      | O(n)    	| O(n)        | O(n<sup>2</sup>)|
|2      | O(n)     	| inf.    	| O(n)		|
|3      | O(n<sup>2</sup>) | O(n)     	| O(n)		|

3A, 2B, 1C are 'hard'

Convert from coeff. to samples and samples to coeff.
in O(nlgn)
