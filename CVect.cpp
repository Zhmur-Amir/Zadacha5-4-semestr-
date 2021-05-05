#pragma once
#include "CVect.h"

ostream &operator<<(ostream &cout,  CVect &s){s.print(); return cout;}
ostream &operator<<(ostream &cout,  const CVect &s){s.print(); return cout;}

void CVect :: print()const
{
        cout<<"("<<arr[0]<<", "<<arr[1]<<", "<<arr[2]<<")";
}

CVect CVect :: operator+(const CVect&b)const
{
    float* crr=new float[3];
    for(int i=0; i<3;i++)
    {
        crr[i]=arr[i]+b.arr[i];
    }
    CVect c(crr);
    return c;
}
CVect CVect :: operator-(const CVect&b)const
{
    float* crr=new float[3];
    for(int i=0; i<3;i++)
    {
        crr[i]=arr[i]-b.arr[i];
    }
    CVect c(crr);
    return c;
}
float CVect :: operator*(const CVect&b)const
{
    float* res=new float[3];
    float ser;
    for(int i=0; i<3;i++)
    {
        res[i]=arr[i]*b.arr[i];
    }
    ser=res[0]+res[1]+res[2];
    return ser;
}

  CVect :: CVect(const vector<float> brr)
    {
      arr=new float[3];
      for(int i=0; i<3; i++)
        {
            arr[i]=brr[i];
        }
    }

void CVect :: CopyOnly(const float* brr)
{
    arr=new float[3];
    for(int i=0; i<3; i++)
    {
        arr[i]=brr[i];
    }
}

void CVect :: CopyOnly(const float a,const float b,const float c)
{
    arr=new float[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
}

 void CVect :: CopyOnly(const CVect &b)
 {
    arr=new float[3];
    for(int i=0; i<3; i++)
    {
        arr[i]=b.arr[i];
    }
}

CVect CVect :: operator*(const float b)
{
    float* crr=new float[3];
    for(int i=0; i<3;i++)
    {
        crr[i]=arr[i]*b;
    }
    CVect c(crr);
    return c ;
}
CVect CVect :: norm()
{
   float b;
   b=len();
   float* crr=new float[3];
   for(int i=0; i<3;i++)
    {
        crr[i]=arr[i]/b;
    }
    CVect c(crr);
    return c;
}
