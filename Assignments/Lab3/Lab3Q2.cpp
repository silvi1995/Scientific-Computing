#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double function(double val);
int main()
{
	double first=24;
	double second=25;
	double mid;
	double tol=pow(10,-27);
	double temp;
	temp=function(first);
	if(fabs(temp)<=tol)
	{
		cout<<first<<" "<<temp;
		return 0;
	}
	temp=function(second);
	if(fabs(temp)<=tol)
	{
		cout<<second<<" "<<temp;
		return 0;
	}
	while(1)
	{
		mid=(first+second)/2;
		cout<<mid<<" "<<function(mid)<<endl;
		if(fabs(function(mid))<=tol)
			return 0;
		if(function(first)*function(mid)>0)
			first=mid;
		else
			second=mid;
	}
}
double function(double val)
{
	return log((val*val)+1)-(exp(0.4*val)*cos(3.14*val));
}
