#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==1)
     return 1;
    else 
    return n*fact(n-1);
}

int main()
 {
	int x,number,original,sum=0,rem;
	cin>>x;
	while(x--)
	{   sum=0;
	    cin>>number;
	    original=number;
	    while(number!=0)
	    {
	        rem=number%10;
	        if(rem!=0)
	        sum+=fact(rem);
	        number=number/10;
	        
	    }
	    if(sum==original)
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    
	}
	return 0;
}
