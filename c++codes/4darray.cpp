#include<iostream>
using namespace std;
int main()
{
    int arr[2][2][2][2],i,j,k,l;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    cin>>arr[i][j][k][l];
                }
            }
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    cout<<arr[i][j][k][l]<<" ";
                }
            }
        }
    }
    return 0;
    
}

