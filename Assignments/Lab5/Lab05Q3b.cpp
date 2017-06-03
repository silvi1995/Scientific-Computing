#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
int low=-5;
int high=5;
int points=11;
double h=(double)(high-low)/(points-1);

double function(double x);
int main()
{
	double dp[points][points];
	for(int i=0;i<points;i++)
		dp[i][i]=function(low+i*h);
	int j;
	for(int l=1;l<points-1;l++)
	{
		for(int i=0;i<points;i++)
		{
			j=i+l;
			if(j>=points)
				break;
			dp[i][j]=(dp[i+1][j]-dp[i][j-1])/((low+j*h)-(low+i*h));
		}
	}
	for(int i=0;i<points;i++)
		cout<<"Coefficient"<<" "<<i+1<<" : "<<dp[0][i]<<endl;
	cout<<endl;
}
double function(double x)
{
	return 1/(1+x*x);
}

