#include<iostream>
using namespace std;

int volume(int);
double volume(double,int);
long volume(long,int,int);

int main()
    {
        cout<<"calling volume() function for computing volume of cube-"<<volume(10)<<"\n";
        cout<<"calling volume() function for computing volume of cylinder-"<<volume(2.5,8)<<"\n";
        cout<<"calling volume() function for computing volume of rectangular box-"<<volume(100L,75,15)<<"\n";
      return 0;
    }
    
int volume(int s)
    {
        return (s*s*s);
    }
double volume(double r,int h)
    {
        return (3.14519*r*h);
    }
long volume(long l,int b,int h)
    {
    
        return (l*b*h);
    }
    
    
    
    
    
    
    
    
