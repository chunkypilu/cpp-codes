#include<iostream>
using namespace std;
int main()
{
    int num[]={56,75,22,18,90};
    int *ptr,i;
    cout<<"Array values: \n";
    for(i=0;i<5;i++)
        cout<<num[i]<<"\n";
        
    ptr =num;
    cout<<"Value of ptr: "<<*ptr<<"\n";
    ptr++;
    cout<<"Value of ptr++: "<<*ptr<<"\n";
    ptr--;
    cout<<"Value of ptr--: "<<*ptr<<"\n";
    ptr+=2;
    cout<<"Value of ptr+2: "<<*ptr<<"\n";    
    ptr--;
    cout<<"Value of ptr--: "<<*ptr<<"\n";
    ptr+=3;
    cout<<"Value of ptr+3: "<<*ptr<<"\n";
    ptr-=2;
    cout<<"Value of ptr-2: "<<*ptr<<"\n";
}
