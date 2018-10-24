#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
 {
	int x;
	float a,b,c,s,area,in_root;
	cin>>x;
	//setprecision(6);
	while(x--)
	{
	    cin>>a>>b>>c;
	    s=(a+b+c)/2;
	    in_root=s*(s-a)*(s-b)*(s-c);
	    if(in_root>0)
	       area=sqrt(in_root);
	   else
	       area=0;
	   
	   
        cout << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(4)
        << area<<endl;
	    //cout<<area<<"\n";
	}
	return 0;
}
