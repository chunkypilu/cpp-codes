#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter values of a and b: \n";
    cin>>a>>b;
    int x=a-b;
    try
    {
        if(x!=0)
        {
            cout<<"Result (a/x)="<<a/x<<"\n";
            
        }
        else
        {
            throw(x);
        }
        
    }
    catch(int i)
    {
        cout<<"Exception caught: divide by zero\n";
    }
    cout<<"END";
    return 0;
}
