#include<bits/stdc++.h>
using namespace std;
int lengthfunction(string s)
{
   int i=0,j=0,ans=0,n=s.length();
   set<char> s1;
   set<char> :: iterator it,it1;
   
   while(i<n&&j<n)
   {
       
       
       it=s1.find(s[j]);
          for(it1=s1.begin();it1!=s1.end();it1++)
             {
                    cout<<(*it1)<<" ";
             }
             cout<<endl;
             
       
         if(it==s1.end())
         {
             
             s1.insert(s[j++]);
             ans=max(ans,j-i);
         }
         else
         {
             cout<<"remove = "<<s[i]<<" "<<endl;
             s1.erase(s[i++]);
                for(it=s1.begin();it!=s1.end();it++)
             {
                    cout<<(*it)<<" ";
             }
             cout<<endl;
             
             
         }
   
   }
             
  
   
   return ans;

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<lengthfunction(s)<<endl;
    }

return 0;

}

