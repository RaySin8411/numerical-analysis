## **Chebyshev Polynomials and Chebyshev Series**
*  Chebyshev Polynomials
	1. Chebyshev's differential equation:
	$$(1-x^2)y^{"}-xy^'+\lambda y in which -1 \leq x \leq$$
	2. Two-term recursion formula:
	$$T_{n+1}(x)=2xT_n(x)-T_{n-1}(x) with T_0(x)=1, T_1(x)=x$$
	3. An orthogonal set:
	$$\int_{-1}^1 \frac{1}{\sqrt{1-x^2}}T_n(x)T_m(x)dx=\begin{cases}
	0, n\neq m\\
	\pi, n=m=0\\
	\frac{x}{\pi}, n=m\neq 0\\
	$$