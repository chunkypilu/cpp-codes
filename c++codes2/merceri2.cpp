#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[4][3],i,j,m,n,ans=0;
    bool blocked[4][3];
    memset(blocked,false,sizeof(blocked));
    
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
         
        //cout<<blocked[i][j]<<" ";
        
        }
    
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
         
        A[i][j]=0;
        
        }
    
    } 
    A[2][0]=1;
    A[1][2]=1;

    i=0;
    j=0;
    while(i!=3&&j!=2)
    {
        if(!blocked[i-2][j+1])
        {
           if(i>=0&&i<4&&j>=0&&j<3)
           {
                i=i-2;
               j=j+1;
              ans++; 
           } 
          
        }
        else if(!blocked[i-2][j-1])
        {
        
        if(i>=0&&i<4&&j>=0&&j<3)
        {
               i=i-2;
          j=j-1;
          ans++;

        
                }
                }
        else if(!blocked[i+2][j+1])
        {
        
        if(i>=0&&i<4&&j>=0&&j<3)
        {
          i=i+2;
          j=j+1;
          ans++;
        }}
        else if(!blocked[i+2][j-1])
        {
        if(i>=0&&i<4&&j>=0&&j<3)
        {
           i=i+2;
          j=j-1;
          ans++;
        }}
    }
    
    
    cout<<i<<" "<<j<<endl;
    cout<<ans;



    return 0;
}
