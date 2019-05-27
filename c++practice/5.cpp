#include<bits/stdc++.h>
//#define n 4
using namespace std;
int n;

void func(int n,int arr[10][10])
{

   //cout<<"in func"<<arr;
  int i, j;
 
  for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
     cout<<arr[i][j]<<" ";
  }
  cout<<endl;
 }


}

int main()
{
 int i, j;
 n=4;
 int arr[10][10];
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
     arr[i][j]=i*j;
  }
 }
  
for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
     cout<<arr[i][j]<<" ";
  }
  cout<<endl;
 }
 
 
 /*
 cout<<arr<<endl;
 cout<<&arr<<endl;
 cout<<&arr[0][0]<<endl;
 //cout<<(&arr[0][0]-&arr[0][0]);
 */
 
 func(n,arr);

return 0;
}


//arr          0x7ffe9a528a50
//&arr         0x7fffb3052850
//*arr         0x7ffca1e3f900
//&arr[0][0]   0x7fff40facdb0
//&arr[0][0]-&arr[0][1]  -1
//&arr[0][0]-&arr[0][2]  -2
//&arr[0][0]-&arr[1][0]  -4
//&arr[0][0]-&arr[2][0]  -8
//&arr[0][0]-&arr[3][0]  -12



1
84
37 28 16 44 36 37 43 50 22 13 28 41 10 14 27 41 27 23 37 12 19 18 30 33 31 13 24 18 36 30 3 23 9 20 18 44 7 12 43 30 24 22 20 35 38 49 25 16 21 14 27 42 31 7 24 13 21 47 32 6 26 35 28 37 6 47 30 14 8 25 46 33 46 15 18 35 15 44 1 38 9 27 29 39
85

Its Correct output is:
1

And Your Code's output is:
0


