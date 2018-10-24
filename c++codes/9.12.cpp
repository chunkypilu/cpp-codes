#include <iostream>
using namespace std;

class Base
{
    public:
     void display(){cout<<"\ndisplay base";}
     virtual void show(){cout<<"\nshow base";}
};
class Derived: public Base
{
    public:
     void display(){cout<<"\ndisplay derived";}
     void show(){cout<<"\nshow derived";}
};
int main()
{
    Base B;
    Derived D;
    Base *bptr;
    
    cout<<"\nbptr points to base\n";
    bptr=&B;
    bptr->display();
    bptr->show();
    
    cout<<"\nbptr points to derived\n";
    bptr=&D;
    bptr->display();
    bptr->show();
    
    return 0;
}
