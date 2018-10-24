#include<bits/stdc++.h>
//#include <unordered_set>
using namespace std;
bool Findarr(unordered_set<int> &s,vector<int >&v)
{
    int i;
    unordered_set<int> :: iterator it;
    for(i=0;i<v.size();i++)
    {
    
    it=s.find(v[i]);
         if(it==s.end())
            return false;
    }
        return true;
}
int main()
 {
	int t,n1,n2,i,val;
	unordered_set<int> s;
	vector<int >v;
	cin>>t;
	//t=1;
	while(t--)
	{
	    cin>>n1>>n2;
	    for(i=0;i<n1;i++)
	    {
	        cin>>val;
	        s.insert(val);
	    }
	    for(i=0;i<n2;i++)
	    {
	        cin>>val;
	        v.push_back(val);
	    }
	    
	    if(Findarr(s,v))
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
