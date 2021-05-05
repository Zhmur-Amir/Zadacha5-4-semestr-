#pragma once
#include "CVect.h"

class CObject
{
CVect colour;

public:
    /*CObject(){CVect c; colour=c;}
    ~CObject(){colour.Clean();}
    CObject(const CObject &b){colour.SetZero(); colour=b.colour;}
    CObject(const CVect &b){colour.SetZero(); colour=b;}*/
    void paintit(CVect&b){colour=b;}
    CVect colour1()const{return colour;}
    virtual CVect centr1()const=0;
    virtual bool intersect(const CVect& orig, const CVect& dir,float &dist, bool &out,float a0, float a1, const CVect& norm)const=0;
    friend CVect ray(const CVect& orig, const CVect& dir,vector<CObject*> &objs, float a0, float a1, const CVect& norm);

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

};


void painter8000(const CVect& cam,const CVect& nor, const CVect& ron,const float a0,const float a1 ,const double alpha,  int width, int height, vector<CObject*> &objs );
CVect ray(const CVect& orig, const CVect& dir,vector<CObject*> &objs, float a0,float a1, const CVect& norm);
bool full_intersect(const CVect& orig, const CVect& dir, float a0, float a1, const CVect& norm, vector<CObject*> &objs, CVect& pnt, CVect& N, CVect& color);
void gradient(const CVect& orig, const CVect& nor,const float a0, const float a1,CObject* obj);










