#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double function(double val);
double derivativeFunction(double preVal,double prepreVal);
void secantMethod(double initialVal);
int main()
{
	double initialVal;
	cin>>initialVal;
	secantMethod(initialVal);
}
void secantMethod(double initialVal)
{
	double preVal,prepreVal,currVal;
	prepreVal=0.5;
	preVal=initialVal;
	int Iter=0;
	double tol=0.000001;
	while(1)
	{
		currVal=preVal-function(preVal)/derivativeFunction(preVal,prepreVal);
		Iter++;
		cout<<currVal<<" "<<function(currVal)<<endl;
		if(fabs(currVal-preVal)/fabs(preVal)<=tol)
			break;
		prepreVal=preVal;
		preVal=currVal;
	}
	cout<<endl<<"Max Iterations : "<<Iter;
}
double function(double val)
{
	return 1000000*exp(val)+435000*(exp(val)-1)/val-1564000;
}
double derivativeFunction(double preval,double prepreval)
{
	return (function(preval)-function(prepreval))/(preval-prepreval);
}
