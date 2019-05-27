/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,count=0;
    map<int ,int > m;
    map<int ,int> :: iterator it;
    cin>>t;
    while(t--)
    {
        count++;
        int x,number,i,a;
    //    cin>>a>>b>>c;
        vector<int> v;
        for(i=0;i<3;i++)
        {
            cin>>x;
            v.push_back(x);   
        }
        sort(v.begin(),v.end());
        number=v[0]*100+v[1]*10+v[2];
        //m[number]=1;
       
          it=m.find(number);
          if(it!=m.end())
           {
            a=(*it).second;
            a++;
            m[number]=a;
           }
          else
           {
            m[number]=1;
           }
        
    }
    
    for (it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    
    // it=m.find(234);
    //cout<<(*it).first;
    
    
    return 0;
    
}
