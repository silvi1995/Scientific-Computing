#include<bits/stdc++.h>

using namespace std;
double alpha = 2*pow(10,-12);
double T0 =2500;
double Ta = 250;
double function(double T);
double functionSecant(double delt,double Tpre,double preT);
double functionDerSecant(double delt,double Tpre,double preT,double prepreT);
double secantMethod(double delt,double Tpre);
int main()
{
    double delt[] = {2,1,0.05,0.025,0.01};
    double currT,preT;
    cout<<"Euler Explicit\n";
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        for(int i=1;i<=10;i++)
        {
            currT = preT + function(preT)*delt[j];
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = currT;
        }
        cout<<endl;
    }
    cout<<"Euler Implicit\n";
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        for(int i=1;i<=10;i++)
        {
            currT = secantMethod(delt[j],preT);
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = currT;
        }
        cout<<endl;
    }
    double halfp;
    cout<<"Modified Euler\n";
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        for(int i=1;i<=10;i++)
        {
            halfp = preT + delt[j]*0.5*function(preT);
            currT = preT + delt[j]*function(halfp);
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = currT;
        }
        cout<<endl;
    }
    cout<<"Fourth order Runge Kutta\n";
    double dely1,dely2,dely3,dely4,val;
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        for(int i=1;i<=10;i++)
        {
            dely1 = delt[j]*function(preT);
            dely2 = delt[j]*function(preT+dely1*0.5);
            dely3 = delt[j]*function(preT+dely2*0.5);
            dely4 = delt[j]*function(preT+dely3);
            val = (dely1 + 2*dely2 + 2*dely3 + dely4)/6;
            currT = preT + val;
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = currT;
        }
        cout<<endl;
    }
}
double secantMethod(double delt,double Tpre)
{
    double currT,prepreT,preT;
    preT = Tpre;
    prepreT = preT + 1;
    int MaxIter = 100;
    while(MaxIter--)
    {
        currT = preT -functionSecant(delt,Tpre,preT)/functionDerSecant(delt,Tpre,preT,prepreT);
        prepreT = preT;
        preT = currT;
        if(fabs(currT-preT)/fabs(preT) <= 0.000001)
            break;
    }
    return currT;
}
double functionDerSecant(double delt,double Tpre,double preT,double prepreT)
{
    return (functionSecant(delt,Tpre,prepreT) -functionSecant(delt,Tpre,preT))/(prepreT-preT);
}
double functionSecant(double delt,double Tpre,double preT)
{
    return (preT - Tpre) + alpha*delt*(pow(preT,4) - pow(Ta,4));
}
double function(double T)
{
    return -alpha*(pow(T,4)-pow(Ta,4));
}
