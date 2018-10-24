#include<iostream>
#include<cstring>
using namespace std;
int main()
 {
	int t,len,i,sum1=0,sum2=0;
	string s;
	
	
	cin>>t;
	while(t--)
	{   sum1=0;sum2=0;
	    cin>>s;
	    len=s.length();
	    char s1[len+1],s2[len+1];
	    
	    
	    for(i=0;i<len;i++)
	    {
	        if(i%2==0)
	        {
	            s1[i]='0';
	            s2[i]='1';
	        }
	        else
	        {
	            s1[i]='1';
	            s2[i]='0';
	        }
	        
	    }
	    s1[i]='\0';
	    s2[i]='\0';
	            
	   // cout<<"s1="<<s1<<endl;
	    //cout<<"s2="<<s2<<endl;
	    
	    for(i=0;i<len;i++)
	    {
	        if(s[i]!=s1[i])
	             sum1++;
	        if(s[i]!=s2[i])
	             sum2++;
	    }
	    
	   // cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;
	    
	    if(sum1>sum2)
	        cout<<sum2<<endl;
	    else
	        cout<<sum1<<endl;
	        
	    
	}
	
		return 0;
}
