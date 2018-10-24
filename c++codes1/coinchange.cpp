#include<iostream>
#include<cmath>
using namespace std;
int totalWays(int coin[],int n,int total)
{
    int T[n][total+1],i,j;
    
    for(i=0;i<=total;i++)
        T[0][i]=i;
        
    for(i=0;i<n;i++)
        T[i][0]=0;
        
    for(i=1;i<n;i++)
       { for(j=1;j<=total;j++)
            {
                if(j<coin[i])
                    {
                        T[i][j]=T[i-1][j];
                        cout<<"T["<<i<<"]["<<j<<"]"<<T[i][j]<<endl;    
                     
                    }
                else 
                {
                    T[i][j]=min((T[i][j-coin[i]]+1),T[i-1][j]);
                    cout<<"T["<<i<<"]["<<j<<"]"<<T[i][j]<<endl;
                }
                        
            }
            
        }   
        
        cout<<"i="<<i<<" "<<"j="<<j ;
    return T[i-1][j-1];
}


int main()
{
    int total=4,coin[4]={1,2,3};
    int n=sizeof(coin)/sizeof(coin[0]);
    //cout<<"n="<<n<<endl;
    cout<<"Answer="<<totalWays(coin,n,total)<<endl;
    return 0;
    
}
