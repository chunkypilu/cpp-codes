#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    int t,n,i,incl,excl,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        incl=arr[0];
        excl=0;
        
        for(i=1;i<n;i++)
        {   
            k=excl;
            excl=max(incl,excl);
            incl=k+arr[i];
            
        }
        
        cout<<max(incl,excl)<<endl;
        
        
    }
    return 0;
}
