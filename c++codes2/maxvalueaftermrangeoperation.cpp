#include<iostream>
#include <algorithm>
using namespace std;

int* increment(int a,int b,int k,int *arr)
{

    int i;
    for(i=a;i<=b;i++)
    {
        arr[i]+=k;
    }
    
    return arr;


}


int main()
{
    int x,i;
    cin>>x;
    while(x--)
    {   int N=0,M=0,a=0,b=0,k=0;
        cin>>N>>M;
        int arr[N]={0};
        int *p;
        while(M--)
        {
            cin>>a>>b>>k;
            
            p=increment(a,b,k,arr);
        }
        
        cout << *std::max_element(p,p+N)<<endl; 
    
    }


    return 0;
}
