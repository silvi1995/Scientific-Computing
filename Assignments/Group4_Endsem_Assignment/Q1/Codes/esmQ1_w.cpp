#include<bits/stdc++.h>

//beta value 0.5 , 1 , 1.5
using namespace std;
int xmin = 0;
int xmax = 4;
int ymin = 0;
int ymax = 1;
int xrange = xmax - xmin;
int yrange = ymax - ymin;

double boundFunction(double x)
{
    return 200*x*(x-4);
}
int main()
{
    FILE *fp = fopen("With_w_For_Beta_1.5_delx_0.025.txt","w");
    double delx,dely,beta;
    cout<<"Enter delx and beta" ;
    cin>>delx>>beta;
    dely = delx/beta;
    int xPoints = 1 + floor(xrange/delx);
    int yPoints = 1 + floor(yrange/dely);
    double temperature[xPoints][yPoints],temperatureFinal[xPoints][yPoints];
    for(int i=0;i<xPoints;i++)
    {
        temperature[i][0] = boundFunction(i*delx);
        temperature[i][yPoints-1] = 0;
        temperatureFinal[i][0] = boundFunction(i*delx);
        temperatureFinal[i][yPoints-1] = 0;
    }
    for(int i=0;i<yPoints;i++)
    {
        temperature[0][i] = temperature[xPoints-1][i] = 0;
        temperatureFinal[0][i] = temperatureFinal[xPoints-1][i] = 0;
     }
     for(int i=1;i<xPoints-1;i++)
     {
         for(int j=1;j<yPoints-1;j++)
            temperature[i][j] = 0;
     }

     //Gauss Seidel

     long long int count = 0;
     long long int MaxIter = 0;
     long long MinIter = LLONG_MAX;
     double wOpt;
     double w ;

    for(w=0.1;w<2;w+=0.1)
    {
        MaxIter = 0;
        while(1)
        {
            count = 0;
            for(int i=1;i<xPoints-1;i++)
            {
                for(int j=1;j<yPoints-1;j++)
                {
                    temperatureFinal[i][j] = temperature[i][j] + w*(temperature[i+1][j] + beta*beta*temperature[i][j+1] + temperatureFinal[i-1][j] + beta*beta*temperatureFinal[i][j-1] - temperature[i][j]*(2*(1+beta*beta)))/(2*(1+beta*beta));
                }
            }
            for(int i=1;i<xPoints-1;i++)
            {
                for(int j=1;j<yPoints-1;j++)
                {
                    if(fabs(temperature[i][j]-temperatureFinal[i][j])/fabs(temperature[i][j]) <= 0.0001)
                        count++;
                    temperature[i][j] = temperatureFinal[i][j];
                }
            }
            MaxIter++;
            if(count == (xPoints-2)*(yPoints-2))
                break;
        }
        for(int i=1;i<xPoints-1;i++)
        {
            for(int j=1;j<yPoints-1;j++)
                temperature[i][j] = 0;
        }
        if(MaxIter < MinIter)
        {
             MinIter = MaxIter;
             wOpt = w;
        }
        fprintf(fp,"%lf %lld\n",w,MaxIter);
    }
    cout<<wOpt<<" "<<MinIter<<endl;
}
