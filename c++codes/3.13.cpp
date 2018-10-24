#include<iostream>
using namespace std;

void f(int &x)
{

x=x+10;
cout<<"x="<<x<<"\n";

}

int main()
{
  int m=10;
  f(m);
  cout<<"m="<<m<<"\n";

return 0;
}
