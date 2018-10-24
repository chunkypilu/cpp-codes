#include<iostream>
using namespace std;

bool subSetSum(int set[],int n,int sum)
{
    int i,j;
    bool T[n][sum+1];
    for(i=0;i<=n;i++)
        T[i][0]=true;
    //for(i=0;i<=sum;i++)
      //  T[0][i]=false;
        
//     for (int i = 1; i <= input.length; i++) {
//            for (int j = 1; j <= total; j++) {
//                if (j - input[i - 1] >= 0) {
//                    T[i][j] = T[i - 1][j] || T[i - 1][j - input[i - 1]];
//                } else {
//                    T[i][j] = T[i-1][j];
//                }
//            }
//        }
//return T[input.length][total];

   
    for(i=1;i<=n;i++)
        for(j=1;j<=sum;j++)
        {
            if(set[i-1]>j)
                    T[i][j]=T[i-1][j];
            else
               T[i][j]=T[i-1][j]||T[i-1][j-set[i-1]];        
        }    
        
        
        //cout<<"i="<<i<<" "<<"j="<<j ;
        return T[n][sum];
}
int main()
{
    int set[6]={3, 34, 4, 12, 5, 2},sum=7;
    if(subSetSum(set,6,sum))
    {
        cout<<"found"<<endl;
    }    
    else
    {
        cout<<"not found"<<endl;
    }
    return 0;
}
