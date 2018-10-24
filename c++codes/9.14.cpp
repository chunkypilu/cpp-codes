#include<iostream>
using namespace std;

class Balagurusamy
{
public:
   virtual void example() { cout << "I am Balagurusamy" << endl; }
     
};

class C:public Balagurusamy
{
    public:
     void example()
     {
        cout<<"C by samy";
     }
};

class oops: public Balagurusamy
{
    public:
     void example()
     {
        cout<<"C++ by samy";
     }
};

int main()
{
    Balagurusamy* arr[2];
    
    C e1;
    oops e2;
    arr[0]=&e1;
    arr[1]=&e2;
    
    arr[0]->example();
    arr[1]->example();
    
    Balagurusamy p;
    p.example();
    
    return 0;
}
