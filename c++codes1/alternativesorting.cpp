#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int x;
   cin>>x;
   while(x--)
   {
    int no_ele,i;
    cin>>no_ele;
    int arr[no_ele];
    for(i=0;i<no_ele;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+no_ele,greater<int>());
    int arr1[no_ele],j=0;
    for(i=0;i<no_ele;i++)
    {
        if(i%2==0)
        {
            arr1[i]=arr[j]; j++;
        }
            
    }
    
   // cout<<"j="<<j;
    for(i=no_ele-1;i>=0;i--)
    {
        if(i%2==1)
        {
            arr1[i]=arr[j]; j++;
        }
            
    }
    for(i=0;i<no_ele;i++)
    {
        cout<<arr1[i]<<" ";
    }  
    cout<<endl;

   } 
    return 0;
    
}
