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
    painter8000(cam,nor,ron,a0,a1,alpha,width,height,objects,lights);
    return 0;
}
