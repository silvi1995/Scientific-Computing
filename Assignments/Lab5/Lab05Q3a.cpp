#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
int low = 0;
int high = 14;
int points = 15;
double h = (double)(high - low)/(points - 1);

double functionx(double t);
double functiony(double t);
void ThomasMethod(double c[],double a[]);
double poly(double x,int j,double a,double b,double c,double d);

int main()
{
	FILE *fp=fopen("plot.txt","w");
	double coefficientx[points-1][4],coefficienty[points-1][4];
	double ax[points],cx[points-2],ay[points],cy[points-2];
	for(int i=0;i<points;i++)
		ax[i]=functionx(low+i*h);
    for(int i=0;i<points;i++)
		ay[i]=functiony(low+i*h);
	ThomasMethod(cx,ax);
	ThomasMethod(cy,ay);
	for(int i=0;i<points-1;i++)
	{
		coefficientx[i][0]=ax[i];
		if(i==0)
			coefficientx[i][2]=0;
		else
			coefficientx[i][2]=cx[i-1];
	}
	for(int i=0;i<points-1;i++)
	{
		if(i!=0)
			coefficientx[i][1]=(ax[i+1]-ax[i])/h-h*(2*cx[i-1]+cx[i])/3;
		else
			coefficientx[i][1]=(ax[i+1]-ax[i])/h-h*cx[i-1]/3;
	}
	for(int i=0;i<points-1;i++)
	{
		if(i==points-2)
			coefficientx[i][3]=-coefficientx[i][2]/(3*h);
		coefficientx[i][3]=(coefficientx[i+1][2]-coefficientx[i][2])/(3*h);
	}
	for(int i=0;i<points-1;i++)
    {
        printf("%0.6lf %0.6lf %0.6lf %0.6lf\n",coefficientx[i][0],coefficientx[i][1],coefficientx[i][2],coefficientx[i][3]);
    }
    cout<<endl;
	for(int i=0;i<points-1;i++)
	{
		coefficienty[i][0]=ay[i];
		if(i==0)
			coefficienty[i][2]=0;
		else
			coefficienty[i][2]=cy[i-1];
	}
	for(int i=0;i<points-1;i++)
	{
		if(i!=0)
			coefficienty[i][1]=(ay[i+1]-ay[i])/h-h*(2*cy[i-1]+cy[i])/3;
		else
			coefficienty[i][1]=(ay[i+1]-ay[i])/h-h*cy[i-1]/3;
	}
	for(int i=0;i<points-1;i++)
	{
		if(i==points-2)
			coefficienty[i][3]=-coefficienty[i][2]/(3*h);
		coefficienty[i][3]=(coefficienty[i+1][2]-coefficienty[i][2])/(3*h);
	}
	for(int i=0;i<points-1;i++)
    {
        printf("%0.6lf %0.6lf %0.6lf %0.6lf\n",coefficienty[i][0],coefficienty[i][1],coefficienty[i][2],coefficienty[i][3]);
    }
    double t;
    int i = 0;
    long long int count = 0;
    for(t = 0 ; t <= 23 ; t = t+0.01)
    {
        count++;
        fprintf(fp,"%lf %lf\n",poly(t,i,coefficientx[i][0],coefficientx[i][1],coefficientx[i][2],coefficientx[i][3]),poly(t,i,coefficienty[i][0],coefficienty[i][1],coefficienty[i][2],coefficienty[i][3]));
        if(count == 100)
        {
            i++;
            count = 0;
        }
    }

}
double poly(double x,int j,double a,double b,double c,double d)
{
	return a+b*(x-(low+j*h))+c*(x-(low+j*h))*(x-(low+j*h))+d*(x-(low+j*h))*
	(x-(low+j*h))*(x-(low+j*h));
}
double functionx(double t)
{
    if(t == 0)
        return 2;
    if(t == 1)
        return 2.8;
    if(t == 2)
        return 3.2;
    if(t == 3)
        return 3.4;
    if(t == 4)
        return 3;
    if(t == 5)
        return 3.2;
    if(t == 6)
        return 3.8;
    if(t == 7)
        return 3.5;
    if(t == 8)
        return 3.2;
    if(t == 9)
        return 3.8;
    if(t == 10)
        return 4.2;
    if(t == 11)
        return 4.5;
    if(t == 12)
        return 4;
    if(t == 13)
        return 4.2;
    if(t == 14)
        return 5.2;
}
double functiony(double t)
{
    if(t == 0)
        return 1.5;
    if(t == 1)
        return 3;
    if(t == 2)
        return 4.8;
    if(t == 3)
        return 6.5;
    if(t == 4)
        return 6;
    if(t == 5)
        return 4.8;
    if(t == 6)
        return 3.8;
    if(t == 7)
        return 2.2;
    if(t == 8)
        return 3;
    if(t == 9)
        return 3.8;
    if(t == 10)
        return 5;
    if(t == 11)
        return 6.7;
    if(t == 12)
        return 6;
    if(t == 13)
        return 5;
    if(t == 14)
        return 3.2;
}
/*double functionx(double t)
{
	if(t == 0)
        return 102;
    if(t == 1)
        return 96;
    if(t == 2)
        return 88;
    if(t == 3)
        return 64;
    if(t == 4)
        return 96;
    if(t == 5)
        return 118;
    if(t == 6)
        return 138;
    if(t == 7)
        return 113;
    if(t == 8)
        return 118;
    if(t == 9)
        return 131;
    if(t == 10)
        return 132;
    if(t == 11)
        return 112;
    if(t == 12)
        return 131;
    if(t == 13)
        return 149;
    if(t == 14)
        return 184;
    if(t == 15)
        return 180;
    if(t == 16)
        return 190;
    if(t == 17)
        return 184;
    if(t == 18)
        return 202;
    if(t == 19)
        return 208;
    if(t == 20)
        return 221;
    if(t == 21)
        return 224;
    if(t == 22)
        return 247;
    if(t == 23)
        return 260;
}
double functiony(double t)
{
	if(t == 0)
        return -308;
    if(t == 1)
        return -227;
    if(t == 2)
        return -162;
    if(t == 3)
        return -197;
    if(t == 4)
        return -227;
    if(t == 5)
        return -240;
    if(t == 6)
        return -284;
    if(t == 7)
        return -277;
    if(t == 8)
        return -240;
    if(t == 9)
        return -178;
    if(t == 10)
        return -103;
    if(t == 11)
        return -120;
    if(t == 12)
        return -178;
    if(t == 13)
        return -240;
    if(t == 14)
        return -193;
    if(t == 15)
        return -235;
    if(t == 16)
        return -207;
    if(t == 17)
        return -193;
    if(t == 18)
        return -212;
    if(t == 19)
        return -163;
    if(t == 20)
        return -202;
    if(t == 21)
        return -150;
    if(t == 22)
        return -183;
    if(t == 23)
        return -133;
}*/
void ThomasMethod(double c[],double a[])
{
	double 	A[points-2],B[points-2],C[points-2],F[points-2];
	for(int i=0;i<points-2;i++)
	{
		A[i]=h;
		B[i]=4*h;
		C[i]=h;
		F[i]=(3*(a[i+2]-a[i+1])-3*(a[i+1]-a[i]))/h;
	}
	for(int i=1;i<points-2;i++)
	{
		B[i]=B[i]-C[i]*A[i]/B[i-1];
		F[i]=F[i]-F[i-1]*A[i]/B[i-1];
	}
	c[points-3]=F[points-3]/B[points-3];
	for(int i=points-4;i>=0;i--)
	{
		c[i]=(F[i]-C[i]*c[i+1])/B[i];
	}
}
