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


/* 
 * Aitken's method for solving equation F(x) = x
 * Input:
 * x0 - the initial approximation of the solution
 * Output:
 * y - the resulted approximation of the solution
 * Return:
 * The number of iterations passed
 */
int AitkenMethodForEquation(double& y, double x0,double error)
{
    int n = 1;
    double x;

    do
    {
        x = f(x0);

        y = x + 1 / ((1 / (f(x) - x)) - (1 / (x - x0)));
		
		cout <<"²Ä"<<n<<"¦¸:"<<y<<"\n";
        
		n++;

        x0 = x;
        
        
        
    }
    while((fabs(y - f(y)) > error) && (n <= MAX_ITERATIONS));

    return n;
}

int main()
{
  	double y,x0,error;
  	
	cout << "Enter y value: ";
	cin >> y;
  	cout << "Enter x0 value: ";
  	cin >> x0;
	cout << "Enter error value: ";
  	cin >> error;
  	
	AitkenMethodForEquation(y,x0,error);
	return 0; 
}
