#include<iostream>
#include<vector> 
using namespace std;

   
        int main() {
    	int i;
    	vector <int> v1,v2;
    	
    	v1.push_back(1);
    	v1.push_back(2);
    	v1.push_back(3);
    	v2.push_back(4);
    	v2.push_back(5);
    	v2.push_back(6);
    	vector <int> v3=v1;
    	v3.insert(v3.end(), v2.begin(), v2.end());
    	//enter input string
    	for(i=0;i<v3.size();i++)
    	{
    	    cout<<v3[i]<<" ";
    	}
//    	    for(i=0;i<=100;i++)
//    	    {
//    	        //what should I write here??
//    	        if(b[i]!='a')
//    	        {
//    	           printf("%c",b[i]); 
//    	        }
//    	    }
    	return 0;
        }
