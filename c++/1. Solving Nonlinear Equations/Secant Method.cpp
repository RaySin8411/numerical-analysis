//Algorithm of the Secant Method:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Given x0 and x1  that are near the root,
//Repeat
//	Set x2 = x1 - f(x1)*(x0 - x1)/(f(x0)-f(x1))
//	
//	Set x0 = x1
//	Set x1 = x2
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
  
  if (function(intervalBegin) * function(intervalEnd) > 0.0f){
    cout << "Function has same signs at ends of interval";
    return -1;
  }
  
  do{    
    	intervalBegin=intervalEnd;                
    	intervalEnd=middle;                
    	middle=intervalEnd-(intervalEnd-intervalBegin)/(function(intervalEnd)-function(intervalBegin))*function(intervalEnd);    
    	if (function(middle)==0){
        	cout<<"\nThe root of the equation is "<<middle;    //print the root
        	return 0;
    	}
	}while(abs(middle-intervalEnd) >= 2*precision);            //check if the error is greater than the desired accuracy
	cout<<"\nThe root of the equation is "<<middle;    //print the root
  //retrun 0;
}

static double function(double x)
{ //x^3 -x -11.0
  return pow(x,3)-x-11.0 ;
}
