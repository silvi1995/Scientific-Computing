#include<bits/stdc++.h>

using namespace std;
int main()
{
    FILE *fp = fopen("exactQ1.txt","w");
    int yrange = 1;
    int N = 1000;
    double delx,dely,beta,sum;
    cin>>delx>>beta;
    double pi = atan(1);
    dely = delx/beta;
    int yPoints = 1 + floor(yrange/dely);
    fprintf(fp,"0.00000 -800.000\n");
    for(int i=1;i<yPoints;i++)
    {
        sum = 0;
        for(int j=1;j<=N;j+=2)
        {
            sum += -(2*sin(j*2*pi)*sinh(j*pi*(i*dely-1)))/(j*j*j*sinh(-j*pi));
        }
        sum = (sum*12800)/(pi*pi*pi*64);
        fprintf(fp,"%lf %lf\n",i*dely,sum);
    }
}
