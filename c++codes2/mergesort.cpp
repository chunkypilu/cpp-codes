#include<bits/stdc++.h>
using namespace std;
int arr[10]={1,65,8,98,7,5,26,15,158,9};
int  *mergesort(int arr[10],int n,int i,int j)
{
    
   if(n==1)
   {
       return arr;
   }
   else
   {
   
        int k,a;
    for(k=i,a=0;k<=j;k++,a++)
    {
      arr[a]=arr[k];
    }

   
        /*if(n%2==0)
        {
            int x=n/2;
            return (mergesort(arr,x,0,x-1),mergesort(arr,n-x,x,n-1));     
        }
        else
        {
                int x=n/2;
            return (mergesort(arr,x+1,0,x),mergesort(arr,n-x-1,x+1,n-1));
        }
   */
        int x=n/2;
        return (mergesort(arr,n%2==0?x:x+1,0,n%2==0?x-1:x),mergesort(arr,n%2==0?n-x:n-x-1,n%2==0?x:x+1,n-1));
   }
}
        
    
int main()
{

    int *ptr,i;
    ptr=mergesort(arr,10,0,9);
    for(i=0;i<10;i++)
    {
       cout<<*(ptr +i)<<" ";
    }
    
    return 0;
}
