#include <iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

int main() {
	//code
	clock_t t1,t2;
    t1=clock();
	int t,n,x,rot;
	cin>>t;
	while(t--)
	{
	    cin>>n>>rot;
	    vector<int>v;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    int no;
	    no=rot%n;
	    rotate(v.begin(),v.begin()+no,v.end());
	    for(int i=0;i<n;i++)
	        cout<<v[i]<<" ";
	    cout<<endl;
	    
	}
	t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<seconds<<endl;
    //system ("pause");
    
    
	return 0;
}
