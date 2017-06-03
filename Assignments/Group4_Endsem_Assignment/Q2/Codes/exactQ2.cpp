#include<bits/stdc++.h>

using namespace std;

double GetExact(double re,double x)
{
    return (exp(re*x)-1)/(exp(re)-1);
}

int main()
{
    FILE *fp = fopen("exactQ2_Re_100.txt","w");
    double delx,re;
    cin>>delx>>re;
    int xPoints = 1 + floor((double)1/delx);
    for(int i=0;i<xPoints;i++)
        fprintf(fp,"%lf %lf\n",i*delx,GetExact(re,i*delx));
}
