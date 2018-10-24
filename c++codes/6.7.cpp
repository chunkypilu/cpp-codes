#include<iostream>
using namespace std;
int count=0;
class test
{
    public:
        test()
        {
        count++;
        cout<<"\n constructor mssg: object no. "<<count<<"created ";
        
        }
        ~test()
        {
        cout<<"\n destructor mssg: object no. "<<count<<"destroyed ";
        count--;
        
        }


};
int main()
{
    cout<<"Inside main block";
    cout<<"\n\nCreating first object T1...";
    test T1;
    { //Block1
        cout<<"\n\nInside block1...";
        cout<<"\n\nCreating two more object T2 and T3..";
        test T2,T3;
        cout<<"\n\nLeaving block1..";
    
    }
    cout<<"\n\nBack inside main block...";
    return 0;   
}
