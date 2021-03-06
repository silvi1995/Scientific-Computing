#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
int low=0;
int high=13;
int points=5;
double functionDistance(double t);
double NewtonPoly(double coefficient[],double val,double xVal[]);

int main()
{
	double dp[points][points];
	double xVal[5];
	xVal[0]=0;xVal[1]=3;xVal[2]=5;xVal[3]=8;xVal[4]=13;
	for(int i=0;i<points;i++)
		dp[i][i]=functionDistance(xVal[i]);
	int j;
	for(int l=1;l<points-1;l++)
	{
		for(int i=0;i<points;i++)
		{
			j=i+l;
			if(j>=points)
				break;
			dp[i][j]=(dp[i+1][j]-dp[i][j-1])/(xVal[j]-xVal[i]);
		}
	}
	double coefficient[points];
	for(int i=0;i<points;i++)
		coefficient[i]=dp[0][i];
	cout<<NewtonPoly(coefficient,10,xVal);
}
double NewtonPoly(double coefficient[],double x,double xVal[])
{
	double sum=0;
	double prod;	
	for(int i=0;i<points;i++)
	{
		prod=1;		
		for(int j=0;j<i;j++)
			prod=prod*(x-xVal[j]);
		sum+=prod*coefficient[i];
	}
	return sum;
}
double functionDistance(double t)
{
	if(t==0)
		return 0;
	if(t==3)
		return 225;
	if(t==5)
		return 383;
	if(t==8)
		return  623;
	if(t==13)
		return 993;
}
