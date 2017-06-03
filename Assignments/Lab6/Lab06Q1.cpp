#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int low=0;
int high=1;
int interval=2000;
double correctArea=atan(1);
double h=(double)(high-low)/(interval-1);
double function(double x);
double Trapezoidal();
double SimpsonOneThird();
double SimpsonThreeEighth();
int main()
{
    cout<<"For interval : "<<interval<<" Trapezoidal Method          : "
    <<Trapezoidal()*4       <<" Error : "<<fabs(correctArea-Trapezoidal())*4<<endl;
    cout<<"For interval : "<<interval<<" Simpson One Third Method    : "
    <<SimpsonOneThird()*4   <<" Error : "<<fabs(correctArea-SimpsonOneThird())*4<<endl;
    cout<<"For interval : "<<interval<<" Simpson Three Eighth Method : "
    <<SimpsonThreeEighth()*4<<" Error : "<<fabs(correctArea-SimpsonThreeEighth())*4<<endl;
}
double function(double x)
{
    return 1/(1+x*x);
}
double Trapezoidal()
{
    double area=0;
    for(int i=0;i<interval;i++)
    {
        area+=(function(low+i*h)+function(low+(i+1)*h))*0.5*h;
    }
    return area;
}
double SimpsonOneThird()
{
    double area=0;
    double y0,y1,y2;
    for(int i=0;i<interval;i++)
    {
        y0=low+i*h;
        y1=y0+h*0.5;
        y2=y0+h;
        area+=h/6*(function(y0)+4*function(y1)+function(y2));
    }
    return area;
}
double SimpsonThreeEighth()
{
    double area=0;
    double y0,y1,y2,y3;
    for(int i=0;i<interval;i++)
    {
        y0=low+i*h;
        y1=y0+h/3;
        y2=y0+(2*h)/3;
        y3=y0+h;
        area+=(h/8)*(function(y0)+3*function(y1)+3*function(y2)+function(y3));
    }
    return area;
}
