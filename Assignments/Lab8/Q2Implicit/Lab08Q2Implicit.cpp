#include<bits/stdc++.h>

using namespace std;
double D = 0.1;
double b = 1;
double boundFunction(double x)
{
	return sin((double)atan(1)*(double)4*x);
}
double Getdelx(double delt)
{
	return sqrt(((double)4*D*delt)/((double)2-b*delt));
}
void SolveGaussSeidel(double arr1[],double arr2[],double b[],double size,double alpha,double beta);
int main()
{
	double delt,delx;
	FILE *fp = fopen("Implicit_Delt_0.0625.txt","w");
	int countx,countt;
	double alpha,beta;
	cout<<"Enter delt"<<endl;
	cin>>delt;
	delx = Getdelx(delt);
	alpha = (D*delt)/(delx*delx);
	beta = b*delt;
	countx = floor((double)1/delx);
	countt = floor((double)1/delt);
	double arr[countx+1],arr1[countx+1],b[countx+1],arr2[countx+1];
	arr[0] = arr[countx] = 0;
    b[0] = b[countx] = 0;
	for(int i=1;i<countx;i++)
	{
		arr[i] = boundFunction(i*delx);
	}
	for(int i=1;i<countx;i++)
    {
        arr1[i] = 0;
        b[i] = (1-alpha-beta/2)*arr[i] + alpha*arr[i+1]*0.5 + alpha*arr[i-1]*0.5;
    }
    arr1[0] = arr1[countx] = 0;
    arr2[0] = arr2[countx] = 0;
	while(countt--)
    {
        SolveGaussSeidel(arr1,arr2,b,countx,alpha,beta);
        for(int i=1;i<countx;i++)
            arr1[i] = 0;
        for(int i=1;i<countx;i++)
        {
            b[i] = (1-alpha-beta/2)*arr2[i] + alpha*arr2[i+1]*0.5 + alpha*arr2[i-1]*0.5;
        }
    }
    for(int i=0;i<countx+1;i++)
    {
        fprintf(fp,"%lf %lf\n",i*delx,arr2[i]);
    }
}
void SolveGaussSeidel(double arr1[],double arr2[],double b[],double size,double alpha,double beta)
{
    int count = 0;
    while(1)
    {
        for(int i=1;i<size;i++)
        {
            arr2[i] = (b[i] + alpha*0.5*arr2[i-1] + alpha*0.5*arr1[i+1])/(1+alpha+beta*0.5);
        }
        for(int i=1;i<size;i++)
        {
            if(fabs(arr1[i]-arr2[i])/fabs(arr1[i]) <= 0.0001)
                count++;
        }
        if(count == size-1)
            break;
        count = 0;
        for(int i=1;i<size;i++)
            arr1[i] = arr2[i];
    }
}
