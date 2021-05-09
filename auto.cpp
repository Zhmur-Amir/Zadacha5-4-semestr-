#pragma once
#include "Light.h"


void autotest(void)
{

     cout<<"Starting Autotest:"<<endl;
     CVect a(9,0,0),b(1,-9,-9),c,f(0,0,0);
     CSphere d(2,2,2,1);
     c=a-b;
     f=d.normal(f);
     if (c[0]==8 && c[1]==9 && c[2]==9 && f[0]==-2 && f[1]==-2 && f[2]==-2 )
     {
         cout<<"Autotest passed! respect+"<<endl;
     }
     else
     {
         cout<<"Autotest failed! Wasted..."<<endl;
     }
     cout<<endl<<"============================="<<endl;






}
