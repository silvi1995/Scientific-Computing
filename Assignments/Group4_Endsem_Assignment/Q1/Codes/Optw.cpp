#include<bits/stdc++.h>

using namespace std;
int main()
{
    double beta,delx,dely,w,epsilon;
    double pi = atan(1)*4;
    cin>>beta>>delx;
    dely = beta/delx;
    epsilon = pow((cos(pi/delx) + beta*beta*cos(pi/dely))/(1+beta*beta),2);
    w = 2*((1-sqrt(1-epsilon))/epsilon);
    cout<<w;
}

