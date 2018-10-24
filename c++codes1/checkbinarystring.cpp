#include<iostream>
#include<cstring>
using namespace std;
int main()
 {
	int x,len,i,j,flag1=0,flag2=0;
	string s;
	
	cin>>x;
	while(x--)
	{   flag1=0;
	    flag2=0;
	    cin>>s;
	    len=s.length();
	    for(i=0;i<len;i++)
	    {flag1=0;
	    flag2=0;
	        if(s.at(i)=='0')
	        {
	            for(j=i-1;j>=0;j--)
	               {
	                   if(s.at(j)=='1')
	                            flag1++;
	               }
	                
	           for (j=i+1;j<len;j++)
	                      {
	                        if(s.at(j)=='1')
	                          flag2++;
	                      }
	               }
	               
	               
	               if((flag1>0)&&(flag2>0))
	                goto label;
	             }
	             
	             
	       label:      if((flag1>0)&&(flag2>0))
	                cout<<"INVALID\n";
	            else
	                cout<<"VALID\n";
	 
	        }
	   
	            
	 
	 

return 0;
}
