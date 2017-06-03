#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double func(double val);
void newtonMethod(double initialVal);
double derivativeFunction(double val);
int main()
{
	double initialVal=1;
	newtonMethod(initialVal);
}
double function(double val)
{
	return pow(val,4)-3*pow(val,2)-21;
}
double derivativeFunction(double val)
{
	return 4*pow(val,3)-6*val;
}
void newtonMethod(double initialVal)
{
	double preVal=initialVal;
	double currVal;
	int Iter=0;
	while(1)
	{
		currVal=preVal-function(preVal)/derivativeFunction(preVal);
		Iter++;
		if(fabs(function(currVal))<=0.000001)
			break;
		preVal=currVal;
	}
	cout<<"Root : "<<currVal<<endl;
	cout<<"Max Iteration : "<<Iter<<endl;
}



