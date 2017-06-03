#include<bits/stdc++.h>

using namespace std;
double b = 1;
double D = 0.1;
double pi = (double)4*atan(1);
double coeff = exp(-b-D*pi*pi);
double func(double x)
{
	return coeff*sin(pi*x);
}
int main()
{
	FILE *fp = fopen("Exact.txt","w");	
	for(double x=0;x<=1;x += 0.02)
		fprintf(fp,"%lf %lf\n",x,func(x));
}
