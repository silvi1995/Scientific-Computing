#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
int main()
{
	double TVal[7];
	double alpha=2;
	double delx=0.0625;
	double a[7],b[7],c[7],f[7];
	b[0]=-(2+2*alpha*alpha*delx);
	for(int i=0;i<7;i++)
	{
		a[i]=1;
		b[i]=b[0];
		c[i]=1;
		f[i]=0;
	}
	f[6]=-100;
	for(int i=1;i<7;i++)
	{
		b[i]=b[i]-(c[i-1]*a[i])/b[i-1];
		f[i]=f[i]-(f[i-1]*a[i])/b[i-1];
	}
	TVal[6]=f[6]/b[6];
	for(int i=5;i>=0;i--)
	{
		TVal[i]=(f[i]-c[i]*TVal[i+1])/b[i];
	}
	for(int i=0;i<7;i++)
	{
		printf("T%d %0.6lf\n",i+1,TVal[i]);
	}
}
