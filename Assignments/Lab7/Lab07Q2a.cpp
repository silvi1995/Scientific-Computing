#include<bits/stdc++.h>

using namespace std;
double alpha = 2*pow(10,-12);
double T0 =2500;
double Ta = 250;
double function(double T);
int main()
{
    //ADAMS BASHFORTH EXPLICIT
    double delt[] = {2,1,0.05,0.025,0.01};
    cout<<"Adams Bashforth Explicit\n";
    double val,preT,currT;
    double fn,fn1,fn2,fn3;
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        fn1 = preT + function(preT)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*1,fn1);
        fn2 = fn1 + function(fn1)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*2,fn2);
        fn3 = fn2 + function(fn2)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*3,fn3);
        for(int i=4;i<=13;i++)
        {
            val = 55*function(fn3)-59*function(fn2)+37*function(fn1)-9*function(preT);
            currT = fn3 + delt[j]*val/24;
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = fn1;
            fn1 = fn2;
            fn2 = fn3;
            fn3 = currT;
        }
        cout<<endl;
    }
    //ADAMS BASHFORTH IMPLICIT
    cout<<"Adams Bashforth Implicit\n";
    for(int j=0;j<5;j++)
    {
        preT = T0;
        printf("For delt = %lf\n",delt[j]);
        fn1 = preT + function(preT)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*1,fn1);
        fn2 = fn1 + function(fn1)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*2,fn2);
        fn3 = fn2 + function(fn2)*delt[j];
        printf("T(%lf) : %lf\n",delt[j]*3,fn3);
        for(int i=4;i<=13;i++)
        {
            val = 9*function(fn3)+19*function(fn2)-5*function(fn1)+function(preT);
            currT = fn3 + delt[j]*val/24;
            printf("T(%lf) : %lf\n",delt[j]*i,currT);
            preT = fn1;
            fn1 = fn2;
            fn2 = fn3;
            fn3 = currT;
        }
        cout<<endl;
    }

}
double function(double T)
{
    return -alpha*(pow(T,4)-pow(Ta,4));
}
