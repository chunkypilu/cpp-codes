#include<iostream>
#include <cmath>
using namespace std;

int break_func(int n)
{
    int dp[n],i;
    dp[0]=0;
    dp[1]=1;
    
    
    for( i=2;i<=n;i++)
    {
        dp[i]=dp[i/2]+dp[i/3]+dp[i/4]; 
        dp[i]=max(i,dp[i]);
        // cout<<"dp["<<i<<"]="<<dp[i]<<" ";
    }
    
    return (dp[n]);
}

int main()
{   
   
    int x;
    cin>>x;
    cout<<break_func(x)<<endl;

    return 0;
    
}
