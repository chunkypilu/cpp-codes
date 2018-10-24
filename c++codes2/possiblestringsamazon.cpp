#include<iostream>
using namespace std;

int main()
{
    char a[]={'a','b'};
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                cout<<a[i]<<a[j]<<a[k]<<endl;
            }
        }
    }
    return 0;
}
