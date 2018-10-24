#include<iostream>
#include<cstring>
using namespace std;

int LCS(char *X,char *Y)
{
    int i,j,m,n;
    m=strlen(X);
    n=strlen(Y);
    int T[m+1][n+1];    
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
        
            if(i==0||j==0)
                T[i][j]=0;
            else if(X[i]==Y[j])
               {
                T[i][j]=1+T[i-1][j-1];cout<<i<<j<<"="<<T[i][j]<<endl;
               } 
            else
               {
                 T[i][j]=max(T[i-1][j],T[i][j-1]);    cout<<i<<j<<"="<<T[i][j]<<endl;
               }  
        }
        
    }
    return T[m][n];
    
    
}


int main()
{
    char X[]="AGGTAB";
    char Y[]="GXTXAYB";
    cout<<"LCS="<<LCS(X,Y);
    return 0;
}
