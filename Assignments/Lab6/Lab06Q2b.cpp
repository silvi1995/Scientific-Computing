#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
double low=0;
double high=1/(double)sqrt(2);
double function(double x);
double SimpsonOneThird(int interval);
int main()
{
    FILE *fp;
    fp=fopen("FileQ2.dat","w");
    int interval=1;
    double area,actualArea;
    actualArea=0.5*atan(1);
    while(1)
    {
        area=SimpsonOneThird(interval);
        cout<<"No of Intervals : "<<interval<<"    "<<"Error : "<<fabs(area-actualArea)<<endl;
        fprintf(fp,"%d %lf\n",interval,fabs(area-actualArea));
        if(fabs(area-actualArea)<=0.5*pow(10,-5))
            break;
        interval=interval+1;
    }
}
double function(double x)
{
    return sqrt(1-x*x)-x;
}
double SimpsonOneThird(int interval)
{
    double area=0;
    double y0,y1,y2,h;
    h=(double)(high-low)/(interval);
    for(int i=0;i<interval;i++)
    {
        y0=low+(double)(i*h);
        y1=y0+h*0.5;
        y2=y0+h;
        area+=h/6*(function(y0)+4*function(y1)+function(y2));
    }
    return area;
}
