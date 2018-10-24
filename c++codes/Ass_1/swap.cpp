#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int t=*a;
        *a=*b;
        *b=t;
}

int main()
{
    int x=2,y=3;
    swap(&x,&y);
    cout<<x<<" "<<y;
    return 0; 
}
