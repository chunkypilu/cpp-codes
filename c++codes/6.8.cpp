#include<iostream>
//#include<conio.h>
using namespace std;
class test
{
    int *a;
    public:
    test(int size)
    {
        a=new int(size);
        cout<<"\n\nConstructor mssg: Integer array of size"<<size<<"created";
    }
    ~test()
    {
        delete a;
        cout<<"\n\nDestructor mssg: Freed up the memory allocted for integer array";
    }
};


int main()
{
    int s;
    cout<<"Enter size of array:";
    cin>>s;
    cout<<"\nCreating an object of test class";
    test T(s);
    cout<<"\nPress any key to end the program..";
    
   // getch();
    return 0;
    
}
