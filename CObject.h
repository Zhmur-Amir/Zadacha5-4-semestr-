#pragma once
#include "CVect.h"

class CObject
{
CVect colour,blesk;

public:
    /*CObject(){CVect c; colour=c;}
    ~CObject(){colour.Clean();}
    CObject(const CObject &b){colour.SetZero(); colour=b.colour;}
    CObject(const CVect &b){colour.SetZero(); colour=b;}*/
    void paintit(CVect&b){colour=b;}
    void glyanetz(CVect&b){blesk=b;}
    CVect colour1()const{return colour;}
    CVect blesk1()const{return blesk;}
    virtual CVect centr1()const=0;
    virtual CVect normal(const CVect&b)const=0;
    virtual bool intersect(const CVect& orig, const CVect& dir,float &dist, bool &out,float a0, float a1, const CVect& norm)const=0;
    friend CVect ray(const CVect& orig, const CVect& dir,vector<CObject*> &objs, float a0, float a1, const CVect& norm);

};



class CPlane : public CObject
{
protected:
    float* arr;
    CVect* crr;
    CVect in;
public:
    CPlane(){SetZero();}
    ~CPlane(){Clean();}
    CPlane(const CPlane &b){SetZero(); CopyOnly(b);}
    void SetZero(){arr=NULL;crr=NULL; in.SetZero();}
    void Clean(){delete[] arr; delete[] crr; SetZero();}
    CPlane &operator=(const CPlane&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    CPlane(const CVect a,const CVect b,const CVect c,const CVect d){SetZero(); CopyOnly(a,b,c,d);};
    CPlane(const float a,const float b,const  float c, const float d,const CVect&a1,const CVect&b1,const CVect&c1,const CVect&d1){SetZero(); CopyOnly(a,b,c,d,a1,b1,c1,d1);};
    void CopyOnly(const CVect m,const CVect n,const CVect c,const CVect d);
    void CopyOnly(const float a,const float b,const float c, const float d,const CVect&a1,const CVect&b1,const CVect&c1,const CVect&d1);
    void CopyOnly(const CPlane &b);
    float &operator[](int i)const{if(i<0 || i>=4) throw -1; return arr[i];}
    //void add_point4(const CVect&a);
    CVect normal(const CVect&b)const{CVect f(arr[0],arr[1],arr[3]),s=crr[0]-in; f=f.norm(); if(f*in<0){return f*(-1);}return f;}
    bool intersect(const CVect& orig, const CVect& dir,float &dist, bool &out,float a0, float a1, const CVect& norm)const;
    CVect centr1()const{return ((crr[0]+crr[1]+crr[2])*0.3);}
};


class CSphere : public CObject
{
 protected:
    CVect centr;
    float rad;
 public:
    CSphere(){SetZero();}
    ~CSphere(){Clean();}
    CSphere(const CSphere &b){SetZero(); CopyOnly(b);}
    void SetZero(){rad=0; centr.SetZero();}
    void Clean(){centr.Clean(); rad=0;}
    CSphere &operator=(const CSphere&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    CSphere(const float a,const float b,const float c,const float d){SetZero(); CopyOnly(a,b,c,d);};
    CSphere(const CVect& a, const float b){SetZero(); CopyOnly(a,b);};
    void CopyOnly(const float a,const float b,const float c,const float d);
    void CopyOnly(const CSphere &b);
    void CopyOnly(const CVect& a, const float b);
    CVect centr1()const{return centr;}
    float rad1()const{return rad;}
    bool intersect(const CVect& orig, const CVect& dir, float &dist, bool &out,float a0, float a1, const CVect& norm)const;
    CVect normal(const CVect&b)const{return (b-centr);}
};












