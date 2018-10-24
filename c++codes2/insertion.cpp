#include<iostream>
using namespace std;

int main()
{

    cout<<"Hello";

    int arr[5]={5,4,0,1,7};
    int i,j,k,x,n=5;
    
    cout<<"Hello";
    for(i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }

    
    
    
//    
    for(i=1;i<n;i++)
    {
    
   for(j=0;j<=i-1;j++)
    {
        if(arr[i]<arr[j])
        {
            x=arr[i];
            for(k=i;k>=j+1;k--)
            {
               arr[k]=arr[k-1];
            }
           arr[j]=x;
            
        }
        
    }
    }
    for(i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }

return 0;
}
