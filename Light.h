#pragma once
#include "CObject.h"


class Light
{
protected:
    CVect cord;
    float power;
public:
    Light(){SetZero();}
    ~Light(){cord.Clean();}
    Light(const Light &b){SetZero(); cord=b.cord; power=b.power;}
    Light(const CVect &b, float p){SetZero(); cord=b; power=p;}
    void SetZero(){CVect c(0,0,0); cord=c; power=0;}
    float power1()const {return power;}
    CVect cord1()const {return cord;}
};


void painter8000(const CVect& cam,const CVect& nor, const CVect& ron,const float a0,const float a1 ,const double alpha,  int width, int height, vector<CObject*> &objs,vector<Light>&lights);
CVect ray(const CVect& orig, const CVect& dir,vector<CObject*> &objs, float a0,float a1, const CVect& norm,vector<Light>&lights);
bool full_intersect(const CVect& orig, const CVect& dir, float a0, float a1, const CVect& norm, vector<CObject*> &objs, CVect& pnt, CVect& N, CVect& color,CVect& bles);
void gradient(const CVect& orig, const CVect& nor,const float a0, const float a1,CObject* obj);
CVect reflect(const CVect &a, const CVect &b);
vector<CObject*> obj_reader(const CVect& cam, const CVect& nor,const float a0, const float a1,const string FileName);
vector<Light> scene_reader(CVect& cam,CVect& nor, CVect& ron,float& a0,float& a1 ,double& alpha,  int &width, int &height,const string FileName);
vector<CObject*> Create_obj(const string str);
void autotest(void);
