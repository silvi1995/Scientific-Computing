#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

double gFunction(double x,double y);
double hFunction(double x,double y);
double gxderivative(double x,double y);
double hxderivative(double x,double y);
double gyderivative(double x,double y);
double hyderivative(double x,double y);
void newtonMethod(double initialx,double initialy);

int main()
{
    double initialx,initialy;
    cin>>initialx>>initialy;
    newtonMethod(initialx,initialy);
}
double gFunction(double x,double y)
{
   //return x*x*x-x-1-3*x*y*y;
  return 2*x*x*x-6*x*y*y-6*x+6*y-6;
  //return sin(x+y)-exp(x-y);
}
double hFunction(double x,double y)
{
   //return 3*x*x*y-y*y*y-y;
  return -2*y*y*y+6*x*x*y-6*y-6*x+6;
  //return cos(x+y)-x*x*y*y;
}
double gxderivative(double x,double y)
{
    //return 3*x*x-3*y*y-1;
    return 6*x*x-6*y*y-6;
   //return cos(x+y)-exp(x-y);
}
double gyderivative(double x,double y)
{
   // return -6*x*y;
   return -12*x*y+6;
   //return cos(x+y)+exp(x-y);
}
double hxderivative(double x,double y)
{
   // return 6*x*y;
  return 12*x*y-6;
  //return -sin(x+6)-2*x*y*y;
}
double hyderivative(double x,double y)
{
   // return 3*x*x-3*y*y-1;
   return -6*y*y+6*x*x-6;
   //return -2*x*x*y;
}
void newtonMethod(double initialx,double initialy)
{
    double preValx,preValy,currValx,currValy;
    preValx=initialx;
    preValy=initialy;
    int Iter=0;
    while(1)
    {
        currValx=preValx-(gFunction(preValx,preValy)*hyderivative(preValx,preValy)-hFunction(preValx,preValy)*gyderivative(preValx,preValy))
                            /(gxderivative(preValx,preValy)*hyderivative(preValx,preValy)-gyderivative(preValx,preValy)*hxderivative(preValx,preValy));
        currValy=preValy-(hFunction(preValx,preValy)*gxderivative(preValx,preValy)-gFunction(preValx,preValy)*hxderivative(preValx,preValy))
                            /(gxderivative(preValx,preValy)*hyderivative(preValx,preValy)-gyderivative(preValx,preValy)*hxderivative(preValx,preValy));
        Iter++;
        if(fabs(currValx-preValx)/fabs(preValx)<0.0000001&&fabs(currValy-preValy)/fabs(preValy)<0.0000001)
            break;
        preValx=currValx;
        preValy=currValy;
    }
    cout<<currValx<<" "<<currValy<<" "<<gFunction(currValx,currValy)<<" "<<hFunction(currValx,currValy)<<endl;
    cout<<"Max Iterations : "<<Iter<<endl;
}
