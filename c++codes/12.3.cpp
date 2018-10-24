#include<iostream>
using namespace std;

template <class T1,class T2>
class Test
{
    T1 a;
    T2 b;
   public:
    Test(T1 x, T2 y)
    {
        a=x;
        b=y;
    } 
    void show()
    {
        cout<<a<<" and  "<<b<<"\n";
    }
};

int main()
{
    cout<<"test1 with float and int data types:\n";
    Test<float,int>test1(1.23,1.23);
    test1.show();
    
    cout<<"test2 with int and char data types:\n";
    Test<int ,char>test2(100,'W');
    test2.show();
    
    return 0;
}
