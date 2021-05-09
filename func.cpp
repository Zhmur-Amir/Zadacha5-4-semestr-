#pragma once
#include "Light.h"




CVect reflect(const CVect &a, const CVect &b)
{
    return (a-(b*2*(a*b)));
}

void gradient(const CVect& orig, const CVect& nor,const float a0, const float a1,CObject* obj)
{
     float w,f;
     CVect cen,norm,van;
     norm=nor.norm();
     w=(a1-a0)/2;
     cen=(obj->centr1());
     van=orig-cen;
     f=abs(van*norm);
     if(f<w)
     {
         CVect c(0,f*2/w,255-f*2/w);
         obj->paintit(c);
     }
     else
     {
         CVect c(0,255-f*2/w,f*2/w);
         obj->paintit(c);
     }


}


bool full_intersect(const CVect& orig, const CVect& dir, float a0, float a1, const CVect& norm, vector<CObject*> &objs, CVect& pnt, CVect& N, CVect& color, CVect& bles)
{
    float min_dist=10*a1;
    for( vector<CObject*>::iterator it=objs.begin(); it!=objs.end(); ++it)
        {
            float dist;
            bool out,res;
            res=((*it)->intersect(orig, dir,dist,out,a0,a1,norm));
            if(res==true && dist<min_dist && out==true)
            {
                min_dist=dist;
                pnt=orig+dir*dist;
                N=((*it)->normal(pnt));
                N=N.norm();
                color=((*it)->colour1());
                bles=((*it)->blesk1());
            }
            else
            {
                if(res==true && dist<min_dist && out==false)
                {
                    min_dist=dist;
                    pnt=orig+dir*dist;
                    N=N=((*it)->normal(pnt))*(-1);
                    N=N.norm();
                    CVect grey(128,128,128);
                    color=grey;
                    bles=((*it)->blesk1());
                }

            }
        }

        return min_dist<a1;

}



CVect ray(const CVect& orig, const CVect& dir, vector<CObject*> &objs ,float a0, float a1, const CVect& norm, vector<Light>&lights)
{
    bool inter;
    float dist;
    CVect pnt,N,color,bles,s(1,1,1);
    inter=full_intersect(orig,dir,a0,a1,norm,objs,pnt,N,color,bles);
    if(inter==false)
    {
        CVect v(0,0,0);
        return v;
    }
    else
    {
        float lght=0,zerk=0;
        for(vector<Light>::iterator it=lights.begin(); it!=lights.end(); ++it)
        {
            CVect lg_dir;
            lg_dir=((*it).cord1())-pnt;
            lg_dir=lg_dir.norm();

            float lg_dist;
            lg_dist=(((*it).cord1())-pnt).len();
            CVect shad_orig, shad_pt, shad_N,shad_color,shad_bles;
            shad_orig=(lg_dir*N<0 ? pnt+N*1e-3 : pnt- N*1e-3);
            if(full_intersect(shad_orig,lg_dir,a0,a1,lg_dir,objs,shad_pt,shad_N,shad_color,shad_bles) &&(shad_pt-shad_orig).len()<lg_dist)
            {
                continue;
            }

            lght+=((*it).power1())*std::max(0.f,lg_dir*N);
            zerk+=powf(std::max(0.f,reflect(lg_dir,N)*dir),bles[2])*((*it).power1());

        }
        return (color*lght*bles[0]*0.25+s*zerk*bles[1]*100);
    }


}



void painter8000(const CVect& cam,const CVect& nor, const CVect& ron,const float a0,const float a1 ,const double alpha,  int width, int height, vector<CObject*> &objs,vector<Light>&lights)
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
    //#pragma omp parallel for
    for (int j=0; j<height;j++)
        {
            for(int i=0; i<width; i++)
            {
                    float x,y,z;
                    x=mron[0]*pixel*(i+0.5-width/2)+vpr[0]*pixel*(-1)*(j+0.5-height/2)+a0*norm[0];
                    y=mron[1]*pixel*(i+0.5-width/2)+vpr[1]*pixel*(-1)*(j-height/2)+a0*norm[1];
                    z=mron[2]*pixel*(i+0.5-width/2)+vpr[2]*pixel*(-1)*(j+0.5-height/2)+a0*norm[2];


                    CVect orig(cam),dir(x,y,z),res;
                    dir=dir.norm();
                    res=ray(orig,dir,objs,a0,a1,norm,lights);
                    img(i,j,0)=res[0];
                    img(i,j,1)=res[1];
                    img(i,j,2)=res[2];

            }
        }

    img.normalize(0,255);
    img.display();
    img.save_bmp("output.bmp");




}



