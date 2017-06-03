#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
double low = 0;
double high = 1;
double xrange = high - low;

double function(double x);
double exact(double x,double re);
void ThomasMethod(double u[],int xPoints,double re,double delx);

int main()
{
	FILE *fp = fopen("Re_100_delx_0.05.txt","w");
	double delx,re;
	int xPoints;
	cin>>delx>>re;
	xPoints = 1 + floor(xrange/delx);
	double u[xPoints];
	u[0] = 0;
	u[xPoints-1] = 1;
	ThomasMethod(u,xPoints,re,delx);
	for(int i=0;i<xPoints;i++)
	{
		fprintf(fp,"%lf %lf\n",i*delx,u[i]);
		printf("%0.2lf %0.6lf\n",i*delx,u[i]);//<<" "<<exact(i*delx,re)<<endl;
	}
}
double exact(double x,double re)
{
	return (exp(re*x)-1)/(exp(re)-1);
}
void ThomasMethod(double u[],int points,double re,double delx)
{
	double 	A[points-2],B[points-2],C[points-2],F[points-2];
	double alpha = re*delx*0.5;
	double a = (double)1+alpha;
	double b = (double)2;
	double c = (double)1-alpha;
	double d = (double)0;
	for(int i=0;i<points-2;i++)
	{
		A[i] = a;
		B[i] = -b;
		C[i] = c;
		F[i] = d;
	}
	F[points-3] = -c;
	for(int i=1;i<points-2;i++)
	{
		B[i] = B[i]-(C[i]*A[i])/B[i-1];
		F[i] = F[i]-(F[i-1]*A[i])/B[i-1];
	}
	u[points-2] = F[points-3]/B[points-3];
	for(int i=points-4;i>=0;i--)
	{
		u[i+1] = (F[i]-(C[i]*u[i+2]))/B[i];
	}
}
