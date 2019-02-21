#include <iostream>
#include <cmath>
#include <math.h> 
#include <iomanip>
#include <valarray>
#include <stdio.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif



using namespace std;


//Si es un array "float []", float * 
float  fn_ha( float x,float *y, float *vk)
{   
	  //double y[100];
	  //y[2] = {1.,0.};	
      vk[1] = y[2];
      vk[2] = -4*M_PI*M_PI*y[1];

}



double drk_ck(double ne,double x,double dx,double eps,double epa,double y2,double ha)
{

int n;
double y[100];
double y1[100] = {0.,1.,0.};
double ai[7] = {0.,0.,1./5.,3./10.,3./5.,1.,7./8.};

map<int,map<int,double>> MatrizBij;
MatrizBij[0][0]=0;MatrizBij[0][1]=0;
double bij[7][6] = {{0.,0.,0.,0.,0.,0.},
	{0.,0.,0.,0.,0.,0.},
	{0.,1./5.,0.,0.,0.,0.},
	{0.,3./40.,9./40.,0.,0.,0.},
	{0.,3./10.,-0.9,1.2,0.,0.},
	{0.,-11./54.,2.5,-70./27.,35./27.,0.},
	{0.,1631./55296.,175./512.,575./13824., 44275./110592.,253.0/4096.}};
double ci[7][3]={{0.,0.,0.},
	{0.,37./378.,2825./27648.},
	{0.,0.,0.},
	{0.,250./621.,18575./48384.},
	{0.,125./594.,13525./55296.},
	{0.,0.,277./14336.},
	{0.,512./1771.,1./4.}};

y[1] = y1[1];
y[2] = y1[2];



float vk[100];

//vk[3] = {0.,y[2],-4*M_PI*M_PI*y[1]};


// Loop over the remaining five steps
      for (int i = 2; i <= 6; i++)
      {
         for (int n = 1; n <= ne; n++)
         { 
		  y[n] = y1[n];	
			for (int j=1; j<= i-1; j++)
			{
				y[n] = y[n] + bij[i][j]*dx*vk[n][j];
			}
		 }
	  }	
	  
      return 0;
}
 

int main()
{
	
	  double ne, x, dx2, dx, eps, epa, y2, ha, v;	
	  ne = 2.;	
	  x = 0.;
	  dx2 = 0.1;
      dx = dx2 / 10.;
	  eps = 1.*pow(10,-13);
      epa = 1.;
	  //y(1) = 1.;		
	  //y(2) = 0.;	
	  ha = 1.*pow(10,10);	

	  v = drk_ck(ne, x, dx, eps, epa, y2, ha);
}
