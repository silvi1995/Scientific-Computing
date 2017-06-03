#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

void newtonMethod(long double initialVal);
long double function(long double val);
long double derivativeFunction(long double val);
int main()
{
	long double initialVal;
	cin>>initialVal;
	newtonMethod(initialVal);
}
void newtonMethod(long double initialVal)
{
	long double preVal=initialVal;
	long double currVal;
	long double tol= pow(10,-16);
	while(1)
	{
		currVal=preVal-function(preVal)/derivativeFunction(preVal);
		cout<<currVal<<" "<<function(currVal)<<endl;
		if(fabs(currVal-preVal)/fabs(preVal)<=tol)
			return;
		preVal=currVal;
	}
}
long double derivativeFunction(long double val)
{
	return pow(27,val)*log(27)-pow(56.25,val)*log(56.25);
}
long double function(long double val)
{
	return pow(3,3*val+1)-pow(7.5,2*val);
}
