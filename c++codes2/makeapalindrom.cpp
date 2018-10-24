#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void output()
{
    int arr['a'+26]={0},len,i,sum=0;
    string s;
    cin>>s;
    len=s.length();
    
    for(i=0;i<len;i++)    
    {
           arr[(int)s.at(i)]++;
           
        
    }
    for(i=97;i<=123;i++)
    {
        sum=sum+arr[i];
    }
        
    cout<<sum-1<<endl;
    
}

int main()
 {
	int x;
	cin>>x;
	while(x--)
	 output( );
	return 0;
}
