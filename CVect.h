#pragma once
#include "wh.h"
using namespace std;

class CVect
{
protected:
    float *arr;
public:
    CVect(){SetZero();}
    CVect(const CVect &b){CopyOnly(b);}
    ~CVect(){Clean();}
    CVect &operator=(const CVect&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    void Clean(){delete[] arr; SetZero();}
    void SetZero(){arr=NULL;}
    void CopyOnly(const CVect &b);
    void CopyOnly(const float* brr);
    CVect(const vector<float> brr);
    CVect(const float* brr){CopyOnly(brr);}
    float &operator[](int i)const{if(i<0 || i>=3) throw -1; return arr[i];}
    CVect operator+(const CVect&b)const;
    CVect operator-(const CVect&b)const;
    float operator*(const CVect&b)const;
    void CopyOnly(const float a,const float b,const float c);
    CVect(const float a,const float b,const float c){SetZero(); CopyOnly(a,b,c);};
    CVect operator*(const float b)const;
    CVect norm()const;
    float len()const{return sqrtf(arr[0]*arr[0]+arr[1]*arr[1]+arr[2]*arr[2]);}
    void print()const;

};

ostream &operator<<(ostream &cout,  CVect &s);
ostream &operator<<(ostream &cout, const CVect &s);

