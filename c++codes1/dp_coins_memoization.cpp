#include<iostream>
#include <cmath>
using namespace std;

int break_func(int n)
{
    int dp[n],i;
    
    for(i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    
    
    
        if(n==0)
            return 0;
        if(n==1)
            return 1;
            
        if(dp[n]==-1)
        {
        
           dp[n]=break_func(n/2)+break_func(n/3)+break_func(n/4);
          // dp[n]=max(n,dp[n]);
          // cout<<"dp["<<n<<"]="<<dp[n]<<" ";
        }        
    
    
                return max(n,dp[n]);  
    
    
    
    
//    for( i=2;i<=n;i++)
//    {
//        dp[i]=dp[i/2]+dp[i/3]+dp[i/4]; 
//        dp[i]=max(i,dp[i]);
//        // cout<<"dp["<<i<<"]="<<dp[i]<<" ";
//    }
//    
//    return (dp[n]);
}

int main()
{   
   
    int x;
    cin>>x;
    cout<<break_func(x)<<endl;

    return 0;
    
}
