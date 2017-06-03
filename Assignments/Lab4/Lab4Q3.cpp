#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

double function(double val);
double derivativeFunction(double val);
double secondDerivativeFunction(double val);
double newFunction(double val);
double newderivativeFunction(double val);
void modifiedNewtonMethod(double initialVal);

int main()
{
	double initialVal;
	cin>>initialVal;
	modifiedNewtonMethod(initialVal);
}

double function(double val)
{
	return exp(val)-val-1;
}
double derivativeFunction(double val)
{
	return exp(val)-1;
}
double secondDerivativeFunction(double val)
{
	return exp(val);
}
double newFunction(double val)
{
	return function(val)/derivativeFunction(val);
}
double newderivativeFunction(double val)
{
	return 1-function(val)*secondDerivativeFunction(val)/pow(derivativeFunction(val),2);
}
void modifiedNewtonMethod(double initialVal)
{
	double preVal=initialVal;
	double currVal;
	int Iter=0;
	while(1)
	{
		currVal=preVal-newFunction(preVal)/newderivativeFunction(preVal);
		Iter++;
		if(fabs(preVal-currVal)/fabs(preVal)<0.0000001)
			break;
		preVal=currVal;
	}
	cout<<"Root is : "<<currVal<<endl;
	cout<<"Max Iterations : "<<Iter<<endl;
}
