//Algorithm of the Linear Interpolation Method:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Given x0 and x1 such that f (x0 ) * f (x1 ) < 0,
//Repeat
//	Set x2 = x1 - f(x1)*(x0 - x1)/(f(x0)-f(x1))
//
//	If f(x2)*f(x0)<0 then
//		Set x1 = x2 
//  Else: 
//		Set x0 = x2
//Until ( | x0 - x1 | < 2 * TOL or |f(x2)|<TOL)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <cmath>
using namespace std;
static double function(double x);

int main() {
  double intervalBegin;
  double intervalEnd;
  double middle;
  double precision;
  
  cout << "Enter begining of interval: ";
  cin >> intervalBegin;
  
  cout << "Enter end of interval: ";
  cin >> intervalEnd;
  
  cout << "Enter precision of method: ";
  cin >> precision;
  
  if (function(intervalBegin) * function(intervalEnd) > 0.0f){
    cout << "Function has same signs at ends of interval";
    return -1;
  }
  
  while (abs(intervalBegin - intervalEnd) >= 2*precision|| function(middle) >= precision)
  {
    middle = intervalEnd-(intervalEnd-intervalBegin)/(function(intervalEnd)-function(intervalBegin))*function(intervalEnd);
    cout << "X: " << middle << endl;
    if (function(intervalBegin) * function(middle) < 0.0f)
    {
      intervalEnd = middle;
    }
    else
    {
      intervalBegin = middle;
    }
  }
}

static double function(double x)
{ //x^3 -x -11.0
  return pow(x,3)-x-11.0 ;
}
