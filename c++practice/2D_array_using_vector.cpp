#include<bits/stdc++.h>
using namespace std;
int main()
{

vector< vector <int> >  A;
int m=3,n=3,i,j;

A.resize(m);

for(i=0;i<m;i++)
{
    A[i].resize(n);

    for(j=0;j<n;j++)
    {
       cin>>A[i][j];
    }
}

for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
       cout<<A[i][j];
    }
}




    return 0;
}
