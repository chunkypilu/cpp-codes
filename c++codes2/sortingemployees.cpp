#include<iostream>
#include<map>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
int main()
 {
	int x,no_employee;
	cin>>x;
	while(x--)
	
	{   //multimap<int,string> empmap;
	    vector<std::pair<int ,string> > empmap;

	    int sal;
	    string name;
	    cin>>no_employee;
	    while(no_employee--)
	    {
	        cin>>name;
	        cin>>sal;
	        //empmap[name]=sal;
	        empmap.insert(std::pair<int,string>(sal,name));
	        
	    }
	    for( vector<std::pair<int ,string> >::iterator ii=empmap.begin(); ii!=empmap.end(); ++ii)
	   {
	       cout << (*ii).second << " " << (*ii).first << endl;
	   }
	}
	return 0;
}
