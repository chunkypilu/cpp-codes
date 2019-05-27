#include <bits/stdc++.h>
using namespace std;

void palindrome(string s)
{
    int n = s.length();
    int i=0;
    int j=n-1;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    while(i<j)
    {
        while(!isalnum(s[i]))
        {
            i++;
        }
        while(!isalnum(s[j]))
        {
            j--;
        }
        if(s[i] != s[j])
        {
            cout<<"NO"<<endl;
            return;
        }
        i++;
        j--;
    }
    cout<<"YES"<<endl;
}

int main() 
{
    freopen("input3.in","r",stdin);
	string s;
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
	    if(i==0)    getline(cin,s);    
	    getline(cin,s);
	    palindrome(s);
	}
	return 0;
}
