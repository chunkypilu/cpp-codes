#include<iostream>
using namespace std;
#include <algorithm>
int count_fib(int *arr,int n)
{
    int a=1,b=1,c,i,j,count=0;
   // max_element=*std::max_element(arr,arr+n);
    int fib_arr[10000];
    fib_arr[0]=0; fib_arr[1]=1;
    for(i=2;i<20;i++)
    {   c=a+b;
        fib_arr[i]=c;
        a=b;b=c;
        //cout<<fib_arr[i]<<" ";
       
    }
    //max_element1=*std::max_element(fib_arr,fib_arr+i-1);
    for(i=0;i<n;i++)
    {        
        for(j=0;j<20;j++)
        {
            if(arr[i]==fib_arr[j])
               count++;
        }
    }
    
        //cout<<"count="<<count;
        return count;
}


int main()
{   
    int x,n,i,ncount;;
    cin>>x;
    while(x--)
    {   
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ncount=count_fib(arr,n);
        cout<<ncount<<endl;
    }
    
    
    return 0;
}
