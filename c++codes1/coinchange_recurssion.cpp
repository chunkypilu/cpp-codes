#include<iostream>
using namespace std;
int Maxnum(int x)
{
    if(x==1||x==0)
    {
        return x;
    }
    else
    {
        //cout<<"Hello "; 
        return max(x,Maxnum(x/2)+Maxnum(x/3)+Maxnum(x/4));
    }
    //cout<<endl;
}

int main()
{
   int x;
   cin>>x;
   cout<<Maxnum(x);


    return 0;
    
}



