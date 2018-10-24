#include<iostream>
using namespace std;
 int main()
 {
    int a=10, *ptr;
    ptr=&a;
    cout<<"Value of a : "<<a<<"\n\n";
    *ptr=(*ptr)/2;
    cout<<"Value of a : "<<*ptr<<"\n\n";
 }
