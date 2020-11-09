// 3x + y^2
#include <iostream> 
#include <cmath> 
#include <iomanip> 
using namespace std;  
int main() 
{     
	double x0=0,y0=1 , h=0.1,y1,y2,y3,y4, y;
	
	y1=3*x0 + y0*y0;   
	y2=3+ 2*y0*y1;   
	y3=2*y1*y1 + 2*y0*y2;   
	y4=6*y1*y2 + 2*y0*y3;    
	
	y= y0+ (y1*h) + (y2*pow(h,2))/2 + (y3*pow(h,3))/6 + (y4*pow(h,4))/24;
	    
	cout << "The value of y when x=0.1 is " << setprecision(5) <<fixed << y << endl;
	
	return 0;
}
  
