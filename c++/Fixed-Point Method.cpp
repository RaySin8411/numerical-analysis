// Algorithm for the Fixed-Point Method:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Given x1 reasonably close to the root,
// Rearrange the equation to an equivalent form x = g(x) .
// Repeat
//  Set x2 = x1
// Set x1 = g(x1)
// Until ( | x1 - x2 | < TOL )
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 
#include <iostream>
#include <cmath>
using namespace std; 
  
const int MAX_ITERATIONS = 10000; 
  
// Function to calculate f(x) 
float f(float x) 
{ 
    return 1/(2*x-3); 
}

int main()
{
  	double p,p0,eps;
  	int i=1;
	
  	cout << "Enter p0 value: ";
	cin >> p0;
  	cout << "Enter eps value: ";
  	cin >> eps;

  	while(i <= MAX_ITERATIONS)
  	{
    	p = f(p0);
    	if(fabs(p-p0) < eps)
    	{
      		cout<<p<<endl;
      		break;
    	}
    	cout<<"Iteration "<<i<<": p = "<<p<<endl;
    	i++;
    	p0 = p;
    	cout<<"The solution is "<<p<<endl;
    	if(i > MAX_ITERATIONS)
    	{
      		cout<<"Solution not found (method diverges)"<<endl;;
      		break;
    	}
  	}
  	
	cout<<"The approximated solution is x = "<<p<<" in the iteration "<<i-1<<endl;

  	return 0;
}
