#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,i,j;
    cin>>n;
    
    if(n==1)
    {
    
    }
    
    else if(n==2)
       cout<<"2";
    else if(n>2)  
    {
    
     cout<<"2";
       
    for(i=3;i<=n;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(i%j==0)
            {
                
                 break;
            }
               
           
        }
       // cout<<i<<","<<j<<endl;
       if(i==j)
          //cout<<i<<","<<j<<endl;
          {
             cout<<","<<i;
          }
       
    }
    }
    return 0;
}
