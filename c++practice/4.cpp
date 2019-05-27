#include<bits/stdc++.h>
using namespace std;

int func(string s1,string s2,int l1,int l2,int p1,int p2)
{
    int i=0,j=0,count=0;
    
    if(l1!=l2)
        return 0;
    while(i<l1&&j<l1)
    {
        if(s1[i]==s2[j])
          {
                  count++;i++;j++; j=j%(l1);
          }
        else
          {
             i=0;count=0;   
             while(s1[i]!=s2[j])
              {
                j++;
              }
          }
         if (count==l1)
            return 1;
    }
    
            return 0;
   
}


int main()
 {
    
    freopen("input1.in","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    int p1,p2, l1=s1.length(),l2=s2.length();
        cout<<func(s1,s2,l1,l2,p1,p2)<<endl;
 	}
	return 0;
}


/*
mightandmagic
andmagicmigth
*/
