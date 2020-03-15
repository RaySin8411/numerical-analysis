/*
¡E There are three disadvantages to use the Lagrangian polynomial for interpolation:
	1) it involves more arithmetic operations than does the divided-difference method;
	
	2) if we desire to add or subtract a point from the set used to construct the polynomial,
		we essentially have to start over in the computation;
	
	3) if we desire to interpolate at a new x-value, we have to repeat all of the computation.

*/
#include<bits/stdc++.h> 
using namespace std; 
  
// To represent a data point corresponding to x and y = f(x) 
struct Data 
{ 
    int x, y; 
}; 
  
// function to interpolate the given data points using Lagrange's formula 
// xi corresponds to the new data point whose value is to be obtained 
// n represents the number of known data points 
double interpolate(Data f[], float xi, float n) 
{ 
    double result = 0; // Initialize result 
  
    for (int i=0; i<n; i++) 
    { 
        // Compute individual terms of above formula 
        double term = f[i].y; 
        for (int j=0;j<n;j++) 
        { 
            if (j!=i) 
                term = term*(xi - f[j].x)/double(f[i].x - f[j].x); 
        } 
  
        // Add current term to result 
        result += term; 
    } 
  
    return result; 
} 
  
// driver function to check the program 
int main() 
{ 
    // creating an array of 4 known data points 
    Data f[] = {{3.2,22.0}, {2.7,17.8}, {1.0,14.2}, {4.8,38.3}}; 
  
    // Using the interpolate function to obtain a data point 
    // corresponding to x=3 
    cout << "Value of f(3) is : " << interpolate(f, 3, 5); 
  
    return 0; 
} 

