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
int main()
{
	double delt,delx;
	FILE *fp = fopen("Explicit_Delt_0.0625.txt","w");
	int countx,countt;
	double alpha,beta;
	cout<<"Enter delt"<<endl;
	cin>>delt;
	delx = Getdelx(delt);
	alpha = (D*delt)/(delx*delx);
	beta = b*delt;
	countx = floor((double)1/delx);
	countt = floor((double)1/delt);
	double arr[countx+1],arr1[countx+1];
	arr[0] = 0;
	for(int i=1;i<countx+1;i++)
	{
		arr[i] = boundFunction(i*delx);
	}
	arr[countx] = 0;
	arr1[0] = arr1[countx] = 0;
	while(countt--)
	{
		for(int i=1;i<countx;i++)
		{
			arr1[i] = arr[i+1]*alpha + arr[i-1]*alpha + (1-beta-2*alpha)*arr[i];
		}
		for(int i=1;i<countx+1;i++)
			arr[i] = arr1[i];
	}
	for(int i= 0;i<countx+1;i++)
	{
		fprintf(fp,"%lf %lf\n",i*delx,arr[i]);
		cout<<i*delx<<" "<<arr[i]<<endl;
	} 
}
