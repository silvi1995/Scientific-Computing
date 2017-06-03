#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
int low=0;
int high=1;
double function(double x);
double integral(double a,double b);
double g(double x,double a,double b);
double GaussThreePointQuad(int interval);
int main()
{
    cout<<"For 1 interval : "<<GaussThreePointQuad(1)<<endl;
    cout<<"For 2 interval : "<<GaussThreePointQuad(2)<<endl;
    cout<<"For 3 interval : "<<GaussThreePointQuad(3)<<endl;
    cout<<"For 4 interval : "<<GaussThreePointQuad(4)<<endl;
}
double function(double x)
{
    return sin(x)/x;
}
double g(double x,double a,double b)
{
    return (b-a)*0.5*function((b-a)*0.5*x+(b+a)*0.5);
}
double integral(double a,double b)
{
    return (5*g(-pow(0.6,0.5),a,b))/9+(8*g(0,a,b))/9+(5*g(pow(0.6,0.5),a,b))/9;
}
double GaussThreePointQuad(int interval)
{
    double area=0;
    double h=(double)(high-low)/interval;
    for(int i=0;i<interval;i++)
    {
        area=area+integral(low+i*h,low+(i+1)*h);
    }
    return area;
}

