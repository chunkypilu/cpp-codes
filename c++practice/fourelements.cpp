#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,sum,x,j;
	    cin>>n;
	    vector<int> v;
	    for(i=0;i<n;i++)
	     {
	         cin>>x;
	         v.push_back(x);
	     }
	    cin>>sum;
	    
	   // for(i=0;i<n;i++)
	     // cout<<v[i]<<" ";
	    sort(v.begin(),v.end());
	    for(i=0;i<n;i++)
	      cout<<v[i]<<" ";
	      
	    int sum1;  
	    for(i=0;i<v.size()-4+1;i++)
	    {
	         sum1=0;
	         for(j=i;j<i+4;j++)
	         {
	             sum1+=v[j];
	         }
	         if(sum1==sum)
	         {
	             cout<<1;
	             break;
	         }
	    }
	      
	      if(sum1!=sum)
	         {
	             cout<<0;
	             //break;
	         }
	    cout<<endl;
	}
	return 0;
}




