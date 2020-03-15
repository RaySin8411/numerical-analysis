## Fourier Series (傅立葉級數)

	* Polynomials are not the only functions that can be used to approximate known functions. Another means for representing known functions are approximations that use sines and cosines, called Fourier series after the French mathematician who first proposed, in the early 1800s,that“any function can be represented by an infinite sum of sine and cosine terms.”

	* Representing a function as a trigonometric series is important in solving some partial differential equations analytically.

* **Fourier Series**
	
	1) Standard Form
	
	![](http://latex.codecogs.com/gif.latex?\frac{1}{2}a_0+\sum_{n=1}^{\infty}[a_ncos(\frac{n\pi%20x}{L})+b_nsin(\frac{n\pi%20x}{L})])

	![](http://latex.codecogs.com/gif.latex?a_0=\frac{1}{L}\int_{-L}^{L}f(x)dx)
	
	![](http://latex.codecogs.com/gif.latex?a_n=\frac{1}{L}\int_{-L}^{L}f(x)cos(\frac{n\pi%20x}{L})dx%20for%20n=1,2,3,...)
	
	![](http://latex.codecogs.com/gif.latex?b_n=\frac{1}{L}\int_{-L}^{L}f(x)sin(\frac{n\pi%20x}{L})dx%20for%20n=1,2,3,...)
	
	2) Phase Angle Form
	
	![](http://latex.codecogs.com/gif.latex?\frac{1}{2}a_0+\sum_{n=1}^{\infty}c_ncos(\frac{n\pi%20x}{L}+\delta_n))
	
	![](http://latex.codecogs.com/gif.latex?c_n=\sqrt{a_n^2+b_n^2})
	
	![](http://latex.codecogs.com/gif.latex?\delta_n=-tan^{-1}(\frac{b_n}{a_n}))

	3) Complex Form
	
	![](http://latex.codecogs.com/gif.latex?\sum_{-\infty}^{\infty}d_ne^{in\omega_0x})
	
	![](http://latex.codecogs.com/gif.latex?d_n=\int_{-L}^{L}f(x)e^{in\omega_0x}dx)
	
	* **The Gibbs Phenomenon (Gibbs 現象)**
		
		The behavior of Fourier series at jump discontinuities of the function is known as the Gibbs phenomenon.
		It means that the peaks in neighbor of the jump discontinuities do not become smaller as N -> ∞. 
		Instead, the peaks maintain roughly the same height, but move closer to the discontinuities as N increases.