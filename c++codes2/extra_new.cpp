#include<iostream>
#include<cstring>
using namespace std;

int main()
 {
	int t,pos,len,i,count=0;
	
	cin>>t;
	
	while(t--)
	{
	    string s;
	    char ch;
	    count=0;
        cin>>s;
        cin>>ch;
        cin>>pos;
        //cout<<"ch="<<ch;
        //cout<<"posn="<<pos;
        len=s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]==ch)
                  count++;
            
            if(count==pos)
                break;
        }
        //cout<<"count="<<count<<"i="<<i+1;
        cout<<s.substr(i+1,len)<<endl;
	}
	return 0;
}




