#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double function1(double val);
double function2(double val);
double function3(double val);
double derivative1(double val);
double derivative2(double val);
double derivative3(double val);
double function(int choice,double val);
double derivativeFunction(int choice,double val);
double derivativeFunction(int choice,double preVal,double prepreVal);
void newtonMethod(double initialVal,int choice);
void secantMethod(double initialVal,int choice);

int main()
{
	double initialVal;
	cin>>initialVal;
	int choice;
	cout<<"Enter choice\n";
	cin>>choice;
	newtonMethod(initialVal,choice);
	//secantMethod(initialVal,choice);
}
double derivativeFunction(int choice,double preVal,double prepreVal)
{
    if(choice==1)
        return (function1(preVal)-function1(prepreVal))/(preVal-prepreVal);
    if(choice==2)
        return (function2(preVal)-function2(prepreVal))/(preVal-prepreVal);
    if(choice==3)
        return (function3(preVal)-function3(prepreVal))/(preVal-prepreVal);
}
void secantMethod(double initialVal,int choice)
{
    double prepreVal=0.5;
    double preVal=initialVal;
    double currVal;
    double tol=pow(10,-4);
    int Iter=0;
    while(1)
    {
        currVal=preVal-function(choice,preVal)/derivativeFunction(choice,preVal,prepreVal);
        cout<<currVal<<" "<<function(choice,currVal)<<endl;
        Iter++;
        if(fabs(function(choice,currVal))<=tol)
        {
            cout<<endl;
            break;
        }
        prepreVal=preVal;
        preVal=currVal;
    }
    cout<<endl<<"Max Iterations : "<<Iter<<endl;
}
double function1(double val)
{
	return pow(val,3)-2*pow(val,2)-5;
}
double function2(double val)
{
	return pow(val,3)+4.001*pow(val,2)+4.002*val+1.101;
}
double function3(double val)
{
	return pow(val,5)-pow(val,4)+2*pow(val,3)-3*pow(val,2)+val-4;
}
double function(int choice,double val)
{
	if(choice==1)
		return function1(val);
	if(choice==2)
		return function2(val);
	if(choice==3)
		return function3(val);
}
double derivative1(double val)
{
	return 3*pow(val,2)-4*val;
}
double derivative2(double val)
{
	return 3*pow(val,2)+8.002*val+4.002;
}
double derivative3(double val)
{
	return 5*pow(val,4)-4*pow(val,3)+6*pow(val,2)-6*val+1;
}
double derivativeFunction(int choice,double val)
{
	if(choice==1)
		return derivative1(val);
	if(choice==2)
		return derivative2(val);
	if(choice==3)
		return derivative3(val);
}
void newtonMethod(double initialVal,int choice)
{
	double preVal=initialVal;
	double currVal;
	int Iter=0;
	double tol=pow(10,-4);
	while(1)
	{
		currVal=preVal-function(choice,preVal)/derivativeFunction(choice,preVal);
		cout<<currVal<<" "<<function(choice,currVal)<<endl;
		Iter++;
		if(fabs(function(choice,currVal))<=tol)
        {
            cout<<endl;
            break;
        }
		preVal=currVal;
	}
    cout<<endl<<"Max Iterations : "<<Iter<<endl;
}


