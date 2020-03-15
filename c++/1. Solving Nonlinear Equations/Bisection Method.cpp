//Algorithm of the Bisection Method:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Given x1 and x2 such that f (x1 ) * f (x2 ) < 0 ,
//Repeat
//	Set x3 = 1/2 (x1 + x2 )
//	If f (x1) * f (x3 ) < 0 then
//		Set x2 = x3
//	Else
//		Set x1 = x3
//	End if
//Until ( | x1 - x2 | < 2 * TOL )
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
  
  if (function(intervalBegin) * function(intervalEnd) > 0.0f)
  {
    cout << "Function has same signs at ends of interval";
    return -1;
  }
  
  while (abs(intervalBegin - intervalEnd) >= 2*precision)
  {
    middle = (intervalBegin + intervalEnd) / 2.0f;
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
  
  return 0;
}

static double function(double x)
{ //x^3 -x -11.0
  return pow(x,3)-x-11.0 ;
}
