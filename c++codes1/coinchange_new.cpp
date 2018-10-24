#include <iostream>
using namespace std;
int noWays(int a[],int n,int sum)
{
   int i,j,T[n][sum+1];
   for(i=0;i<n;i++)
   {
    T[i][0]=1;  cout<<i<<" "<<"0"<<"="<<T[i][0]<<" ";
   }
   cout<<endl;
   for(i=0;i<=sum;i++)
   {
    T[0][i]=1;   cout<<"0"<<" "<<i<<"="<<T[0][i]<<" ";
   }
    cout<<endl;
    
   for(i=1;i<n;i++)
   {
    for(j=1;j<=sum;j++)
    {
        if(a[i]>j)
           {
            T[i][j]=T[i-1][j];   cout<<i<<" "<<j<<"="<<T[i][j]<<" ";
           } 
        else    
        {
        
         T[i][j]=T[i-1][j]+T[i][j-a[i]];  cout<<i<<" "<<j<<"="<<T[i][j]<<" ";
        }
            
    }
    cout<<endl;
   }

    return T[n-1][sum];
}
int main()
{
    int arr[3]={1,2,3};
    cout<<"ways="<<noWays(arr,3,4);
    
    return 0;
}
