#pragma once
#include "CObject.h"



bool CPlane :: intersect(const CVect& orig, const CVect& dir,float &dist, bool &out,float a0, float a1, const CVect& norm)const
{
    CVect v=normal(orig);
    float vect,t,z0,x0,y0,x,y,z;
    vect=v*dir;
    constexpr int ulp=1;

    constexpr float eps=1;


    if(std::fabs(vect)<=eps)
    {
        false;
    }
    t=((arr[0]*orig[0]+arr[1]*orig[1]+arr[2]*orig[2]+arr[3])/(arr[0]*dir[0]+arr[1]*dir[1]+arr[2]*dir[2]));
    if(std::fabs(t)<=eps)
    {
        return false;
    }
    x0=orig[0]-t*dir[0];
    y0=orig[1]-t*dir[1];
    z0=orig[2]-t*dir[2];
    CVect w(x0,y0,z0);
    dist=w.len();
    if (w*norm<a0 ||w*norm>a1)
    {
        return false;
    }

    //b = orig; d = dir;
    //p[i]=crr[i];
    //b-t*d = (1-u-v)*p0+u*p1+v*p2;
    //-t*d+u(p0-p1)+v(p0-p2) = p0-b;
    //          (-d.x  (p0-p1).x  (p0-p2).x)   (t)
    // (p0-b) = (-d.y  (p0-p1).y  (p0-p2).y) * (u)
    //          (-d.z  (p0-p1).z  (p0-p2).z)   (v)
    // (crr[0]-orig)[2]
    //float u,b,det,dett,detu,detv;


     //det = (-1)*dir[0]*(crr[0]-crr[1])[1]*(crr[0]-crr[2])[2]+(crr[0]-crr[1])[0]*(crr[0]-crr[2])[1]*(-1)*dir[2]+(crr[0]-crr[2])[0]*(-1)*dir[1]*(crr[0]-crr[1])[2]
   // -(crr[0]-crr[2])[0]*(crr[0]-crr[1])[1]*(-1)*dir[2]-(crr[0]-crr[1])[0]*(-1)*dir[1]*(crr[0]-crr[2])[2]-(-1)*dir[0]*(crr[0]-crr[2])[1]*(crr[0]-crr[1])[2];




    //dett = (crr[0]-orig)[0]*(crr[0]-crr[1])[1]*(crr[0]-crr[2])[2]+(crr[0]-crr[1])[0]*(crr[0]-crr[2])[1]*(crr[0]-orig)[1] +(crr[0]-crr[2])[0]*(crr[0]-orig)[1] *(crr[0]-crr[1])[2]-(crr[0]-crr[2])[0]*(crr[0]-crr[1])[1]*(crr[0]-orig)[1] -(crr[0]-crr[1])[0]*(crr[0]-orig)[1] *(crr[0]-crr[2])[2]-(crr[0]-orig)[0]*(crr[0]-crr[2])[1]*(crr[0]-crr[1])[2];
    //detu = (-1)*dir[0]*(crr[0]-orig)[1] *(crr[0]-crr[2])[2]+(crr[0]-orig)[0]*(crr[0]-crr[2])[1]*(-1)*dir[2]+(crr[0]-crr[2])[0]*(-1)*dir[1]*(crr[0]-orig)[1] -(crr[0]-crr[2])[0]*(crr[0]-orig)[1] *(-1)*dir[2]-(crr[0]-orig)[0]*(-1)*dir[1]*(crr[0]-crr[2])[2]-(-1)*dir[0]*(crr[0]-crr[2])[1]*(crr[0]-orig)[2];
   // detv = (-1)*dir[0]*(crr[0]-crr[1])[1]*(crr[0]-orig)[1] +(crr[0]-crr[1])[0]*(crr[0]-orig)[1] *(-1)*dir[2]+(crr[0]-orig)[0]*(-1)*dir[1]*(crr[0]-crr[1])[2]-(crr[0]-orig)[0]*(crr[0]-crr[1])[1]*(-1)*dir[2]-(crr[0]-crr[1])[0]*(-1)*dir[1]*(crr[0]-orig)[1] -(-1)*dir[0]*(crr[0]-orig)[1] *(crr[0]-crr[1])[2];



    x=((crr[0]-w)^(crr[1]-w)).len()+((crr[1]-w)^(crr[2]-w)).len()+((crr[2]-w)^(crr[0]-w)).len();
    y=((crr[0]-crr[2])^(crr[0]-crr[1])).len();

//cout<<det<<endl;
/*if(std::fabs(det)<=1.e-3)
    {
        //cout<<"1"<<endl;
        return false;
    }
    u = detu;
    if(u*det < 0.0 || fabs(u-det)<=std::numeric_limits<float>::epsilon()*std::fabs(u+det)*ulp){
        return false;
    }
    b = detv;
    if(b*det < 0.0 || fabs(u+b-det)<=std::numeric_limits<float>::epsilon()*std::fabs(u+b+det)*ulp){
        //cout<<"2"<<endl;
        return false;
    }*/
    //*t = dett/det;
    //out=true;
   // return true;
//cout<<"3"<<endl;



    if (fabs(x-y)<=std::numeric_limits<float>::epsilon()*std::fabs(x+y)*ulp )
    {

    out=true;
    return true;
    }

    return false;

}



void CPlane :: CopyOnly(const CVect m,const CVect n,const CVect c,const CVect d)
{
    CVect a=m-c, b=n-c;
    arr=new float[4];
    arr[0]=a[1]*b[2]-a[2]*b[1];
    arr[1]=a[2]*b[0]-a[0]*b[2];
    arr[2]=a[0]*b[1]-a[1]*b[0];
    arr[3]=(-1)*(arr[0]*c[0]+arr[1]*c[1]+arr[2]*c[2]);
    crr=new CVect[3];
    crr[0]=m;
    crr[1]=n;
    crr[2]=c;
    in=d;
}
void CPlane :: CopyOnly(const float a,const float b,const float c,const float d,const CVect&a1,const CVect&b1,const CVect&c1,const CVect& d1)
{
   if(a1[0]*a+a1[1]*b+a1[2]*c+d!=0 && b1[0]*a+b1[1]*b+b1[2]*c+d!=0 && c1[0]*a+c1[1]*b+c1[2]*c+d!=0)
    {
        throw -2;
    }
    arr=new float[4];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    arr[3]=d;
    crr=new CVect[3];
    crr[0]=a1;
    crr[1]=b1;
    crr[2]=c1;
    in=d1;
}
void CPlane :: CopyOnly(const CPlane &b)
{
    arr=new float[4];
    crr=new CVect[3];
    for(int i=0; i<4; i++)
    {
        arr[i]=b.arr[i];
        crr[i]=b.crr[i];
        in=b.in;
    }
}


/*void CPlane :: add_point4(const CVect&a,const CVect&b,const CVect&c,const CVect&d)
{
    crr=new CVect[4];
    crr[0]=a;
    crr[1]=b;
    crr[2]=c;
    crr[3]=d;

}*/







