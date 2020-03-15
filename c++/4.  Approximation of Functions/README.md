## **Chebyshev Polynomials and Chebyshev Series**
*  Chebyshev Polynomials
	
	1) Chebyshev's differential equation:

		![](http://latex.codecogs.com/gif.latex?(1-x^2)y^{"}-xy^{'}+\lambda%20y=0%20,where%20-1%20\leq%20x%20\leq%201)

	2) Two-term recursion formula:

		![](http://latex.codecogs.com/gif.latex?T_{n+1}(x)=2xT_n(x)-T_{n-1}(x)%20\quad%20with%20\quad%20T_0(x)=1,\quad%20T_1(x)=x)

	3) An orthogonal set:

		![](http://latex.codecogs.com/gif.latex?\int_{-1}^1\frac{1}{\sqrt{1-x^2}}T_n(x)T_m(x)dx=)
							
		![](http://latex.codecogs.com/gif.latex?1.%200,%20n%20\neq%20m)
				
		![](http://latex.codecogs.com/gif.latex?2.%20\pi,%20n=m=0)
				
		![](http://latex.codecogs.com/gif.latex?3.%20\frac{\pi}{2},%20n=m%20\neq%200)
	
* Smallest Upper Bound / Smallest Maximum Error (最小的最大誤差)
	
	![](http://latex.codecogs.com/gif.latex?\frac{1}{2^{n-1}}T_n(x))
	
	* 證明可以用矛盾法(contradiction)去證
	
* Chebyshev Series
	
	The computational economy to be gained by economizing a Maclaurin series or 
	by using a Chebyshev series is even more dramatic when the Maclaurin series is slowly convergent.
	(當 Maclaurin 級數收斂緩慢時，使用 econimized 級數或 Chebyshev 級數來「降低最大誤差」或「將誤差平均化」的效果會更明顯)
	
	優點:
	
		1. at significant savings of computational effor
		
		2. withsmallerstoragerequirementsinacomputer’smemoryforthecoefficients of the polynomials
	
