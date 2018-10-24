#include<iostream>
using  namespace std;

int main()
{
    int a,*ptr1,**ptr2;
    ptr1=&a;
    ptr2=&ptr1;
    
    cout<<"Address of a: "<<ptr1<<"\n";
    cout <<"Address ot ptr1: "<<ptr2<<"\n";
    
    cout<<"\n\n";
    cout<< "After increamenting\n\n";
    
    ptr1+=2;
    cout<<"Address of a: "<<ptr1<<"\n";;
    ptr2+=2;
    cout <<"Address ot ptr1: "<<ptr2<<"\n";
    
    return 0;
}
