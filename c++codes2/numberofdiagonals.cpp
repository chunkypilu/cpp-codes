#include<iostream>
using namespace std;
int main()
 {  
     int x,no_sides,i=3,sum=0;
	cin>>x;
	while(x--)
	{   sum=0;
	i=3;
	    cin>>no_sides;
	    while((no_sides-i)!=0)
	    {   
	        if(i==3)
	              sum=sum+(no_sides-i)*2;
	        else
	             sum=sum+(no_sides-i);
	             
	      i++;           
	           
	            
	    }
	    cout<<sum<<"\n";
	    
	}
	return 0;
}
