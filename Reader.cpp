#pragma once
#include "Light.h"
#include "factory.h"

vector<CObject*> obj_reader(const CVect& cam, const CVect& nor,const float a0, const float a1,const string FileName)
{
    string line;
    vector<string> str;
    ifstream file(FileName);
    if(!file)
    {
        cout<<"Error! Cannot open file..."<<endl;
        throw 1;
    }
    while (getline(file,line))
    {
        str.push_back(line);
    }
    if(str.size()==0)
    {
        cout<<"Input is empty..."<<endl;
        throw 1;
    }
    file.close();
    vector<CObject*> obj;
    for(vector<string>::iterator it=str.begin(); it!=str.end(); ++it)
        {
            vector<CObject*> ob;
            ob=Create_obj(*it);
            obj.insert(obj.end(),ob.begin(),ob.end());
        }
    for( vector<CObject*>::iterator it=obj.begin(); it!=obj.end(); ++it)
    {
        gradient(cam,nor,a0,a1,*it);
    }
    return obj;


}

vector<CObject*> Create_obj(const string str)
{

    map<string, CFactory*>F;
    F["Sphere"]=new CFactory0();
    F["Box"]=new CFactory2();
    F["Tetra"]=new CFactory1();
    stringstream Stream;
    Stream<<str;
    string Type;
    Stream>>Type;
    auto curfabric=F.find(Type);
    if (curfabric==F.end())
    {
        cout<<"Input Syntax Error!"<<endl;
        exit (-4);
    }
    else
    {
        vector<CObject*> product;
        product=curfabric->second->CCreate(str);
        return product;
    }



}

vector<Light> scene_reader(CVect& cam,CVect& nor, CVect& ron,float& a0,float& a1 ,double& alpha,  int &width, int &height,const string FileName)
{

    string line;
    vector<string> str;
    ifstream file(FileName);
    if(!file)
    {
        cout<<"Error! Cannot open file..."<<endl;
        throw 1;
    }
    while (getline(file,line))
    {
        str.push_back(line);
    }
    if(str.size()==0)
    {
        cout<<"Input is empty..."<<endl;
        throw 1;
    }
    if(str.size()<8)
    {
        cout<<"Input is not full..."<<endl;
        throw 1;
    }
    file.close();
        stringstream Stream1,Stream2,Stream3,Stream4,Stream5,Stream6,Stream0;
        string Type;
        float a,b,c;

        Stream0<<str[0];
        Stream0>>Type;
        Stream0>>a;
        Stream0>>b;
        Stream0>>c;
        CVect v0(a,b,c);
        cam=v0;

        Stream1<<str[1];
        Stream1>>Type;
        Stream1>>a;
        Stream1>>b;
        Stream1>>c;
        CVect v1(a,b,c);
        nor=v1;

        Stream2<<str[2];
        Stream2>>Type;
        Stream2>>a;
        Stream2>>b;
        Stream2>>c;
        CVect v2(a,b,c);
        ron=v2;

        Stream3<<str[3];
        Stream3>>Type;
        Stream3>>a0;
        Stream3>>a1;

        Stream4<<str[4];
        Stream4>>Type;
        Stream4>>alpha;

        Stream5<<str[5];
        Stream5>>Type;
        Stream5>>width;

        Stream6<<str[6];
        Stream6>>Type;
        Stream6>>height;

    vector<Light> lght;
    for(int i=7; i<str.size(); i++)
    {
        stringstream Stream;
        Stream<<str[i];
        string Type0;
        float a0,b0,c0,d0;
        Stream>>Type0;
        Stream>>a0;
        Stream>>b0;
        Stream>>c0;
        Stream>>d0;
        CVect l(a0,b0,c0);
        Light lg(l,d0);
        lght.push_back(lg);
    }

    return lght;
}
