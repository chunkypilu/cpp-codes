//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
    int n;
    cin>>n;
    if(n>=1&&n<=9)
        cout<<n<<endl;
    if(n>=10&&n<=99)
        cout<<11+(n-10)*2<<endl;    
    if(n>=100&&n<=999)
        cout<<192+(n-100)*3<<endl;
    if(n>=1000&&n<=9999)        
        cout<<2893+(n-1000)*4<<endl;
    if(n>=10000&&n<=99999)        
        cout<<38894+(n-10000)*5<<endl;
    if(n>=100000&&n<=999999)        
        cout<<488895+(n-100000)*6<<endl;        
    
    }

    return 0;
}
