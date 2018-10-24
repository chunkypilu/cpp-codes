#include<iostream>
using namespace std;
int main()
 {  
     int x,number,original,count=0,rem;
	cin>>x;
	while(x--)
	{   count=0;
	    cin>>number;
	    original=number;
	    while(number!=0)
	    {
	        rem=number%10;
	        number=number/10;
	       if(rem!=0) 
	        if(original%rem==0)
	        {
	            count++;
	        }
	        
	    }
	   cout<<count<<"\n";
	}
	
	return 0;
}
