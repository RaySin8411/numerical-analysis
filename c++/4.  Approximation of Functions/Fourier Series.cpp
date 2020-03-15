#include <stdio.h>
#include <math.h>
#define Npart 10
#define Ndiv 40

using namespace std; 

float funcx( float );
float funcx2( float );


int main()
{
	int i , n;
	float L=2.0 , dx , x , fx , fs , thetax , pi;
	float a0 , an[Npart] , bn[Npart];
	FILE *fPtr1 , *fPtr2;
	
	pi = 4.0 * atanf( 1.0 );

	fPtr1 = fopen( "coeff.dat" , "w" );
	fprintf( fPtr1 , "%6s %8s %10s\n", "n" , "an" , "bn" );
	fPtr2 = fopen( "output.dat" , "w" );
	fprintf( fPtr2 , "%6s %11s %13s\n", "x" , "fx" , "fseries" );
	/* Find a0, an, bn */
	a0 = 0.0;
	for ( n = 1 ; n <= Npart ; n++ ) {
		an[ n ] = 0.0;
		bn[ n ] = 0.0;
	}
	dx = 2.0 * L / Ndiv;
	x = -L + 0.5 * dx;
	for ( i = 1 ; i <= Ndiv ; i++ ) {
		fx = funcx( x );
		a0 += fx;
		for ( n = 1 ; n <= Npart ; n++ ) {
			thetax = n * pi * x / L;
			an[ n ] += fx * cosf( thetax );
			bn[ n ] += fx * sinf( thetax );
		}
		x += dx;
	}
	a0 = a0 * dx / L;
	fprintf( fPtr1 , "%6d %10.6f\n", 0 , a0 );
	for ( n = 1 ; n <= Npart ; n++ ) {
	an[ n ] = an[ n ] * dx / L;
	bn[ n ] = bn[ n ] * dx / L;
	fprintf( fPtr1 , "%6d %10.6f %10.6f\n", n , an[n] , bn[n] );
	}
	/* inverse transform */
	x = -L + 0.5 * dx;
	for ( i = 1 ; i <= Ndiv ; i++ ) {
		fs = 0.5 * a0;
		for ( n = 1 ; n <= Npart ; n++ ) {
			thetax = n * pi * x / L;
			fs += an[ n ] * cosf( thetax ) + bn[ n ] * sinf( thetax );
		}
		fprintf( fPtr2 , "%10.6f %10.6f %10.6f\n", x , funcx(x) , fs );
		x += dx;
	}
	
	fclose( fPtr1 );
	fclose( fPtr2 );
	return 0;
}

/* Function evaluation Example1*/
float funcx( float x )
{
	if ( -2.0 <= x && x < 0.0 )
		return 0.0;
	else
		return 2.0-x;
}

/* Function evaluation Example2*/
float funcx2( float x )
{
	float pi , a1;
	pi = 4.0 * atanf( 1.0 );
	a1 = 0.5 * pi * x;
	return 3.0*cosf(3.0*a1) - 5.0*sinf(5.0*a1) + 7.0*cos(7.0*a1);
}

