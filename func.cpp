#pragma once
#include "CObject.h"


void gradient(int width, int height)
{
     cimg_library::CImg<int>img(width,height,1,3);
     for (int j=0; j<height;j++)
     {
         for(int i=0; i<width; i++)
         {
             img(i,j,0)=i%width;
             img(i,j,1)=j%height;
             img(i,j,2)=1;
         }
     }



    img.display();

}


CVect ray(const CVect& orig, const CVect& dir, CObject* obj,float a0, float a1, const CVect& norm)
{
    bool inter, out;
    float dist;
    inter=obj->intersect(orig,dir,dist,out,a0,a1,norm);

    /*if(inter==true && (dist<a0 || dist>a1))
    {
        CVect v(128,128,250);
        return v;
    }
    else
    {
        if(inter==true && out==false)
        {
            CVect v(128,128,128);
                return v;
        }
        else
        {
            if(inter==true)
            {
                CVect v(250,0,0);
                return v;
            }
            else
            {
                CVect v(0,0,0);
                return v;
            }
        }
    }*/
    if(inter==true && out==false)
        {
            CVect v(128,128,128);
            return v;
        }
        else
        {
            if(inter==true && out==true)
            {
                CVect v(250,0,0);
                return v;
            }
            else
            {
                if(inter==false)
                {
                    CVect v(0,0,0);
                    return v;
                }
            }
        }

}



void painter8000(const CVect& cam,const CVect& nor, const CVect& ron,const float a0,const float a1 ,const double alpha,  int width, int height, CObject* obj)
{
    cimg_library::CImg<int>img(width,height,1,3);
   float pixel,n1,n2,n3;
    pixel=2*a0*tan(alpha/2)/height;
    n1=nor[1]*ron[2]-nor[2]*ron[1];
    n2=nor[2]*ron[0]-nor[0]*ron[2];
    n3=nor[0]*ron[1]-nor[1]*ron[0];
    CVect norm(nor),mron(ron),vpr(n1,n2,n3);
    vpr=vpr.norm();
    norm=norm.norm();
    mron=mron.norm();
    #pragma omp parallel for
    for (int j=0; j<height;j++)
        {
            for(int i=0; i<width; i++)
            {
                    float x,y,z;
                    x=mron[0]*pixel*(i+0.5-width/2)+vpr[0]*pixel*(-1)*(j+0.5-height/2)+a0*norm[0];
                    y=mron[1]*pixel*(i+0.5-width/2)+vpr[1]*pixel*(-1)*(j-height/2)+a0*norm[1];
                    z=mron[2]*pixel*(i+0.5-width/2)+vpr[2]*pixel*(-1)*(j+0.5-height/2)+a0*norm[2];



                    //x =  (2*(i + 0.5)/width  - 1)*tan(alpha/2)*width/height*a0;
                    //y = -(2*(j + 0.5)/height - 1)*tan(alpha/2)*a0;


                    CVect orig(cam),dir(x,y,z),res;
                    dir=dir.norm();
                    res=ray(orig,dir, obj,a0,a1,norm);
                    img(i,j,0)=res[0];
                    img(i,j,1)=res[1];
                    img(i,j,2)=res[2];

            }
        }


    img.display();






}



