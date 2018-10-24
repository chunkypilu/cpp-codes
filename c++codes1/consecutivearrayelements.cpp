#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        for(i=0;i<n;i++)
        {
            if(arr[i+1]==arr[i]+1)
            {
                break;
            }
        }
        
        if(i==n)
          cout<<"NO"<<endl;
         else
          cout<<"YES"<<endl; 
        
    }
    return 0;
}
