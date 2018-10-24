#include<iostream>
#include<algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int x,i,no_ele;
    cin>>x;
    while(x--)
    {
        cin>>no_ele;
        int minVal = INT_MAX;
        int maxVal=INT_MIN;
       
        int arr[no_ele],count=0;
        for(i=0;i<no_ele;i++)
        {
            cin>>arr[i];
        }
        
        sort(arr, arr + no_ele);
        for(i=0;i<no_ele-1;i++)
        {
            if(arr[i]==(arr[i+1]-1))
                    count++;            
            //cout<<arr[i]<<" ";
        }
        
       // cout<<"count= "<<count;
        
        if(count==no_ele-1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;    
            
            cout<<"minVal="<<minVal<<""<<"maxVal="<<INT_MIN;
    }

    return 0;
}
