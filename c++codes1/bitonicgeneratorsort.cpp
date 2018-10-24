#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
 {
	int x,no_ele,i,value;
	cin>>x;
	while(x--)
	{
	    cin>>no_ele;
	    vector <int> v1,v_even,v_odd;
	    for(i=0;i<no_ele;i++)
	    {
	        cin>>value;
	        v1.push_back(value);
	    }
	    for(i=0;i<no_ele;i++)
	    {
	        if(i%2==0)
	           v_even.push_back(v1[i]);
	        else
	           v_odd.push_back(v1[i]);
	    }
	    
	    
	    sort(v_even.begin(),v_even.end());
	    sort(v_odd.begin(),v_odd.end());
	    reverse(v_odd.begin(),v_odd.end());
	    v1=v_even;
	    v1.insert(v1.end(), v_odd.begin(), v_odd.end());
	    for(i=0;i<v1.size();i++)
	    {
	        cout<<v1[i]<<" ";
	    }
	    
	}
	return 0;
}
