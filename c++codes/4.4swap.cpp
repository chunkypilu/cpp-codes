#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
int t=a;
a=b;
b=t;
}

int main()
{

int a=9,b=10;
swap(a,b);
cout<<"a="<<a<<"\n"<<"b="<<b;


}
