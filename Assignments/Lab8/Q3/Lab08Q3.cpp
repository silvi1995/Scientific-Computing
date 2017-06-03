#include<bits/stdc++.h>

using namespace std;
double D = 0.05;
double b = 1;
double delx = 0.1;
double pi = (double)4*atan(1);
double coeff = exp(-b-D*pi*pi);
double exactVal(double x)
{
	return coeff*sin(pi*x);
}
double boundFunction(double x)
{
	return sin((double)atan(1)*(double)4*x);
}
int main()
{
	FILE *fp = fopen("MaxError_Delx_0.05.txt","w");
	int countx,countt;
	double alpha,beta,maxError,error;
	double arr[1000],arr1[1000];
	double delt[] = {0.25,0.125,0.0625,0.03125};
	for(int j=0;j<4;j++)
	{
		alpha = (D*delt[j])/(delx*delx);
		beta = b*delt[j];
		maxError = 0.0;
		countx = floor((double)1/delx);
		countt = floor((double)1/delt[j]);
		arr[0] = arr[countx] = 0;
		for(int i=1;i<countx;i++)
		{
			arr[i] = boundFunction(i*delx);
		}
		arr1[0] = arr1[countx] = 0;
		for(int i=1;i<countx;i++)
		{
			arr1[i] = arr[i+1]*alpha + arr[i-1]*alpha + (1-beta-2*alpha)*arr[i];
		}
		for(int i=1;i<countx+1;i++)
			arr[i] = arr1[i];
		for(int i= 1;i<countx+1;i++)
		{
			error = fabs(arr[i] - exactVal(i*delx));
			if(error > maxError)
				maxError = error;
		}
		fprintf(fp,"%lf %lf\n",delt[j],maxError);
	}
}
