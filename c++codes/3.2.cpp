#include<iostream>
//#include<conio.h>
using namespace std;

int main()
{
   int *arr;
   int size;
   
   cout<<"Enter size of integer array";
   cin>>size;
   
   cout<<"Creating array of size "<<size<<"..";
   arr= new int (size);
   
   cout<<"\nDynamic allocation successfull";   

   delete arr;
   return 0;
}
