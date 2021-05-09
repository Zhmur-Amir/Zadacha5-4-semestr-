#pragma once
#include "Light.h"

int main()
{
    CVect cam,nor,ron;
    float a0,a1;
    double alpha;
    int width, height;
    vector<Light> lights;
    vector<CObject*> objects;
    lights=scene_reader(cam,nor,ron,a0,a1 ,alpha,width,height,"input1.txt");
    objects=obj_reader(cam,nor,a0,a1,"input2.txt");

    /*CVect metal(0.4,0.8,10),a(-3,-1,7),b(-4,3,4),c(-5,-3,6);
    CObject* pln=new CPlane(a,b,c);
    pln->glyanetz(metal);
    gradient(cam,nor,1,20,pln);
    objects.push_back(pln);*/
    autotest();
    painter8000(cam,nor,ron,a0,a1,alpha,width,height,objects,lights);

    return 0;
}
