#include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int size,i,j;
        cin>>size;
        int arr[size],arr1[size-1];
        for(i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        
        for(i=0;i<size;i++)
        {
            if(arr[i]>arr[i+1])
            {
                arr1[i]=1;
                
            }
            else
            {
                arr1[i]=0;
            }
        }
        for(i=0;i<size-1;i++)
        {
            cout<<arr1[i]<<" ";
        }
         int count1=0,count2=0;
        for(i=0;i<size-1;i++)       //for 0 to 1 switch
        {
            if(arr1[i]==0)
                break;
        }
        
        cout<<"1st i="<<i<<endl;
        for(j=i;j<size-1;j++)
        {
            if(arr1[j]!=arr1[j+1])
                count1++;
        }         

        cout<<"count1="<<count1;            




            
        for(i=0;i<size-1;i++)       //for 1 to 0 switch
        {
            if(arr1[i]==1)
                break;
        }
        
        cout<<"2nd i="<<i<<endl;
        
        for(j=i;j<size-1;j++)
        {
            if(arr1[j]!=arr1[j+1])
                count2++;
        }
        
        cout<<"count2="<<count2;
 
        if(count1>count2)
             cout<<count1+2<<endl;
         else
             cout<<count2+2<<endl;           
        
    }
    return 0;
}
