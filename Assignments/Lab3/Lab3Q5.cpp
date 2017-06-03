#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

double function(double initialVal);
void newtonMethod(double initialVal);
double derivativeFunction(double Val);
void secantMethod(double initialVal);
double derivativeFunction(double preVal,double prepreVal);
int main()
{
    double initialVal=-0.9;
    cout<<"Initial Val : "<<initialVal<<endl;
    //newtonMethod(initialVal);
    secantMethod(initialVal);
}
double derivativeFunction(double preval,double prepreval)
{
	return (function(preval)-function(prepreval))/(preval-prepreval);
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
		if((fabs(currVal-1)<=tol)||(fabs(currVal+1)<=tol))
        {
            cout<<endl;
            break;
        }
		prepreVal=preVal;
		preVal=currVal;
	}
	cout<<"Max Iterations : "<<Iter<<endl;
}
double derivativeFunction(double Val)
{
    return pow(Val+1,3)+3*(Val-1)*pow(Val+1,2);
}
void newtonMethod(double initialVal)
{
    double preVal=initialVal;
    double currVal;
    double tol=0.0001;
    int Iter=0;
    while(1)
    {
        currVal=preVal-function(preVal)/derivativeFunction(preVal);
        Iter++;
        cout<<currVal<<" "<<function(currVal)<<endl;
        if((fabs(currVal-1)<=tol)||(fabs(currVal+1)<=tol))
        {
            cout<<endl;
            break;
        }
        preVal=currVal;
    }
    cout<<"Max Iterations : "<<Iter<<endl;
}
double function(double val)
{
    return pow((val+1),3)*(val-1);
}
