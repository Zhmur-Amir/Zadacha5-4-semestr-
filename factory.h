#pragma once
#include "Light.h"


class CFactory
{

public:
    virtual vector<CObject*> CCreate(const string str)=0;

};

class CFactory0 : public CFactory
{
public:
    vector<CObject*> CCreate(const string str)
    {
        stringstream Stream;
        string Type;
        float a,b,c,x,y,z,r;
        Stream<<str;
        Stream>>Type;
        Stream>>a;
        Stream>>b;
        Stream>>c;
        Stream>>x;
        Stream>>y;
        Stream>>z;
        Stream>>r;
        CVect metal(a,b,c);
        CObject* Sph=new CSphere(x,y,z,r);
        Sph->glyanetz(metal);
        vector<CObject*> Sphs;
        Sphs.push_back(Sph);
        return   Sphs;
    }

};

class CFactory1 : public CFactory
{
public:
   vector<CObject*>  CCreate(const string str)
    {
        stringstream Stream;
        string Type;
        float a,b,c,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5;
        Stream<<str;
        Stream>>Type;
        Stream>>a;
        Stream>>b;
        Stream>>c;
        Stream>>x1;
        Stream>>y1;
        Stream>>z1;
        Stream>>x2;
        Stream>>y2;
        Stream>>z2;
        Stream>>x3;
        Stream>>y3;
        Stream>>z3;
        Stream>>x4;
        Stream>>y4;
        Stream>>z4;
        Stream>>x5;
        Stream>>y5;
        Stream>>z5;
        CVect metal(a,b,c),q(x1,y1,z1),w(x2,y2,z2),e(x3,y3,z3),r(x4,y4,z4),t(x5,y5,z5);
        CObject* Pln1=new CPlane(q,w,e);
        CObject* Pln2=new CPlane(q,e,r);
        CObject* Pln3=new CPlane(q,r,w);
        CObject* Pln4=new CPlane(w,e,r);
        Pln1->glyanetz(metal);
        Pln2->glyanetz(metal);
        Pln3->glyanetz(metal);
        Pln4->glyanetz(metal);
        vector<CObject*> Plns;
        Plns.push_back(Pln1);
        Plns.push_back(Pln2);
        Plns.push_back(Pln3);
        Plns.push_back(Pln4);
        return   Plns;
    }

};

class CFactory2 : public CFactory
{
public:
    vector<CObject*>  CCreate(const string str)
    {
        stringstream Stream;
        string Type;
        float a,b,c,x1,y1,z1,x2,y2,z2;
        Stream<<str;
        Stream>>Type;
        Stream>>a;
        Stream>>b;
        Stream>>c;
        Stream>>x1;
        Stream>>y1;
        Stream>>z1;
        Stream>>x2;
        Stream>>y2;
        Stream>>z2;
        CVect metal(a,b,c),
        q1(x1,y1,z1),q2(x2,y1,z1),q3(x1,y1,z2),q4(x2,y1,z2),
        w1(x2,y2,z2), w2(x1,y2,z2), w3(x2,y2,z1), w4(x1,y2,z1);

        CObject* Pln1=new CPlane(q1,q2,q4);
        CObject* Pln2=new CPlane(q1,q3,q4);
        CObject* Pln3=new CPlane(w1,w2,w4);
        CObject* Pln4=new CPlane(w1,w3,w4);
        Pln1->glyanetz(metal);
        Pln2->glyanetz(metal);
        Pln3->glyanetz(metal);
        Pln4->glyanetz(metal);
        vector<CObject*> Plns;
        Plns.push_back(Pln1);
        Plns.push_back(Pln2);
        Plns.push_back(Pln3);
        Plns.push_back(Pln4);

        CObject* Pln11=new CPlane(q1,w2,w4);
        CObject* Pln21=new CPlane(q1,q3,w2);
        CObject* Pln31=new CPlane(w1,q2,q4);
        CObject* Pln41=new CPlane(w1,w3,q2);
        Pln11->glyanetz(metal);
        Pln21->glyanetz(metal);
        Pln31->glyanetz(metal);
        Pln41->glyanetz(metal);

        Plns.push_back(Pln11);
        Plns.push_back(Pln21);
        Plns.push_back(Pln31);
        Plns.push_back(Pln41);

        CObject* Pln12=new CPlane(w2,q3,q4);
        CObject* Pln22=new CPlane(w2,w1,q4);
        CObject* Pln32=new CPlane(q2,w3,w4);
        CObject* Pln42=new CPlane(q2,q1,w4);
        Pln12->glyanetz(metal);
        Pln22->glyanetz(metal);
        Pln32->glyanetz(metal);
        Pln42->glyanetz(metal);

        Plns.push_back(Pln12);
        Plns.push_back(Pln22);
        Plns.push_back(Pln32);
        Plns.push_back(Pln42);

        return   Plns;
    }

};


  /// input example
    /*CVect metal(0.4,0.8,10),metal2(0.5,0.5,100), nemetal(0.9,0.3,10), p1(-3,-1,7),p2(-4,3,4),p3(-5,-3,6);
    CObject* Sph1=new CSphere(3,2,6,1);
    CObject* Sph2=new CSphere(-3,0,14,5);
    CObject* Sph3=new CSphere(7,-0.5,18,1);
    CObject* Sph4=new CSphere(0,-1,7,1);
    CObject* Pln1=new CPlane(p1,p2,p3);
    Sph1->glyanetz(metal);
    Sph2->glyanetz(nemetal);
    Sph3->glyanetz(metal);
    Sph4->glyanetz(nemetal);
    Pln1->glyanetz(metal);
    vector<CObject*> Sphs;
    Sphs.push_back(Sph1);
    Sphs.push_back(Sph2);
    Sphs.push_back(Sph3);
    Sphs.push_back(Sph4);
    Sphs.push_back(Pln1);

   for( vector<CObject*>::iterator it=Sphs.begin(); it!=Sphs.end(); ++it)
    {
        gradient(cam,nor,a0,a1,*it);
    }
    return Sphs;

  ///

    CVect a(0,0,0),b(0,0,1),c(1,0,0), r(5,2,0),r2(30,10,30),r3(30,50,-25);
    a0=1;
    a1=20;
    alpha=1.5;
    cam=a;
    nor=b;
    ron=c;
    width=1024;
    height=768;
    vector<Light> lights;
    Light lght(r,3.5),lght1(r2,3.8),lght2(r3,3.7);
    lights.push_back(lght);
    lights.push_back(lght1);
    lights.push_back(lght2);
    return lights;*/




  /// end






