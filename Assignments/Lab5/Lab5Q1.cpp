#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<stdio.h>

using namespace std;
double function(double val);
void GetCoefficients(vector<double>&coefficients,int interval,double a
                     ,double b,double h);
void GetDiff(vector<double>coefficients,int interval,double a,double b
             ,double h,int interval1,double a1,double b1,double h1);
double polynomial(double x,vector<double> coefficients,int interval,
                  double a,double b,double h);
int main()
{
    double a,b,h,a1,b1,h1;
    int interval,interval1;
    a=0;b=6;interval=11;
    h=(double)(b-a)/(interval-1);
    vector<double>coefficients;
    GetCoefficients(coefficients,interval,a,b,h);
    for(int i=0;i<interval;i++)
       printf("a%d %0.6lf\n",i,coefficients[i]);
    cout<<endl;
    a1=0;b1=8;interval1=33;
    h1=(double)(b1-a1)/(interval1-1);
    //GetDiff(coefficients,interval,a,b,h,interval1,a1,b1,h1);
}
double polynomial(double x,vector<double>coefficients,int interval,
                  double a,double b,double h)
{
    double sum=0;
    double prod=1;
    for(int i=0;i<interval;i++)
    {
        prod=1;
        for(int j=0;j<i;j++)
            prod=prod*(x-(a+j*h));
        sum+=coefficients[i]*prod;
    }
    return sum;
}
void GetDiff(vector<double>coefficients,int interval,double a,double b
             ,double h,int interval1,double a1,double b1,double h1)
{
    for(int i=0;i<interval1;i++)
    {
        printf("For %0.6lf : Error = %0.6lf\n",a1+i*h1,fabs(function(a1+i*h1)-
                    polynomial(a1+i*h1,coefficients,interval,a,b,h)));
    }
}
double function(double x)
{
    return atan(x);
}
void GetCoefficients(vector<double>&coefficients,int interval,double a,
                     double b,double h)
{
    double dp[interval][interval];
    for(int i=0;i<interval;i++)
        dp[i][i]=function(a+(double)(i*h));
    int j;
    for(int l=1;l<interval;l++)
    {
        for(int i=0;i<interval;i++)
        {
            j=i+l;
            if(j>=interval)
                break;
            dp[i][i+l]=(dp[i+1][i+l]-dp[i][i+l-1])/((a+(i+l)*h)-(a+i*h));

        }
    }
    for(int i=0;i<interval;i++)
        coefficients.push_back(dp[0][i]);
}
