#include <bits/stdc++.h>

using namespace std;
double T0 = 2500;
double Ta = 250;
double alpha = 2*pow(10,-12);
double function(double t,double T);
double functionDer(double t,double pre,double prepre);
double secantMethod(double t);
int main()
{
    double t,valT,valFunc;
    for(t=1;t<=10;t++)
    {
        valT = secantMethod(t);
        valFunc = function(t,valT);
        printf("For t: %.0lf , T: %lf f(%.0lf): %lf\n",t,valT,t,valFunc);
    }
}
double functionDer(double t,double pre,double prepre)
{
    return (function(t,pre)-function(t,prepre))/(pre-prepre);
}
double function(double t,double T)
{
    double val = ((T0-Ta)*(T+Ta))/((T-Ta)*(T0+Ta));
    return atan(T/Ta) - atan(T0/Ta) + 0.5*log(val) - 2*alpha*Ta*Ta*Ta*t;
}
double secantMethod(double t)
{
    int maxIter = 100000;
    int Iter = 0;
    double prepre,pre,curr;
    prepre = T0;
    pre = T0+1;
    while(maxIter--)
    {
        curr = pre - function(t,pre)/functionDer(t,pre,prepre);
        prepre = pre;
        pre = curr;
        if(fabs(curr-pre)/fabs(pre) <= 0.000001)
            break;
    }
    return pre;
}
