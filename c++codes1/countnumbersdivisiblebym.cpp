#include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
       int a,b,m,i,count=0;
       cin>>a>>b>>m;
       for(i=a;i<=b;i++)
       {
           if(i%m==0)
            count++;
       }
       
          cout<<count<<endl;
    }
    
    
    return 0;
}
