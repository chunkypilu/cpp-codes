#include<iostream>
using namespace std;


void func(int n,int m,int  *arr)
{

   //cout<<*(arr+1*m+1);
   *(arr+0*m+0)=10;
   *(arr+0*m+1)=11;
   *(arr+1*m+0)=12;
   *(arr+1*m+1)=13;
   cout<<*(arr+1*m+1)<<endl;
}
int main()
{
  
  int n=2,m=2;
  int arr[n][m];
  arr[0][0]=1;
  arr[0][1]=56;
  arr[1][0]=87;
  arr[1][1]=78;
  
  func(n,m,(int *)arr);
  
   cout<<arr[0][0]<<endl;
   cout<<arr[0][1]<<endl;
   cout<<arr[1][0]<<endl;
   cout<<arr[1][1]<<endl;
  
   cout<<arr[1][1];

return 0;
}
