#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> dec_to_bin(int a)
{
    
    vector <int> v;
    while(a!=0)
    {
        v.push_back(a%2);
        a=a/2;
    }
    reverse(v.begin(), v.end());
    return v;
    
      
}

int bin_to_dec(vector<int> &v2)
{
      int dec_val=0,i;
      for(i=0;i<v2.size();i++)
      {
        dec_val=dec_val+v2[i]*pow(2,v2.size()-i-1);
      }
   return dec_val;
}


int main()
 {
	int x,n,k;
	vector<int> v1;
	cin>>x;
	
	while(x--)
	{
	    cin>>n>>k;
	    v1=dec_to_bin(n);
	    
	   
	    
	    if(v1[v1.size()-k-1]==0)
	        v1[v1.size()-k-1]=1;
      
      cout<<bin_to_dec(v1)<<"\n";	    
	    
	}
	
	
	return 0;
}
