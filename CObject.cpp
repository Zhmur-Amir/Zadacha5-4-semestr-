#pragma once
#include "CObject.h"

bool CSphere :: intersect(const CVect& orig, const CVect& dir, float &dist, bool &out,float a0, float a1, const CVect& norm)const
{
    CVect OC,r(0,0,1),m(0,0,0.9);
    OC=orig-centr;
    float proj,cosa;
    proj=OC*dir;
    cosa=norm*dir;
    float CP;
    CP=OC*OC-proj*proj;
    if(CP>rad*rad)
    {
        return false;
    }

    float in,temp1,temp2;
    in=sqrtf(rad*rad-CP);
    temp1=-proj-in;
    temp2=-proj+in;
    dist=temp1*cosa;
    out=true;
    if(dist<a0 || dist>a1 || temp1<0)
    {
        dist=temp2*cosa;
        out=false;

        if(dist<a0 || dist>a1)
        {
           return false;
        }
    }
    return true;
}

void CSphere :: CopyOnly(const float a,const float b,const float c,const float d)
{
    CVect f(a,b,c);
    centr=f;
    rad=d;
}
void CSphere :: CopyOnly(const CSphere &b)
{
    centr=b.centr;
    rad=b.rad;
}
void CSphere :: CopyOnly(const CVect& a, const float b)
{
    centr=a;
    rad=b;
}

