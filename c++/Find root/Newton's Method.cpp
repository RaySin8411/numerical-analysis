//Algorithm of the Secant Method:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Given x0 reasonably close to the root,
//Repeat
//	Set x1 = x0 
//	Compute f(x0), f'(x0)
//	If f'(x0) = 0.0 break
//	Set x1 = x2
//Until ( | x0 - x1 | < TOL or |f(x0)|<TOL )
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cmath>
using namespace std;
static double function(double x);
static double difunction(double x);

int main() {
  double intervalBegin;
  double root;
  double precision;
  
  cout << "Enter begining value: ";
  cin >> intervalBegin;
  
  cout << "Enter precision of method: ";
  cin >> precision;
  
  root = intervalBegin;
  while (abs(intervalBegin - root) >= precision || abs(function(intervalBegin)) >= precision){
    
    cout << "X: " << root << endl;
    if (difunction(intervalBegin) == 0.0) break;
	intervalBegin = intervalBegin - function(intervalBegin)/difunction(intervalBegin);
	root = intervalBegin;
  	}	
}

static double function(double x)
{ //x^3 -x -11.0
  return pow(x,3)-x-11.0 ;
}

static double difunction(double x)
{ //3x^2 -1 
  return 3*pow(x,2)-1 ;
}
