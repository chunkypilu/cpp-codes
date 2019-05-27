#include<bits/stdc++.h>
using namespace std;
int main()
{

   vector<int> v[2];
   vector<int>:: iterator it;
   v[0].push_back(1);
   v[0].push_back(10);
   v[0].push_back(100);
   v[0].push_back(1000); 
   v[0].push_back(0);
   for(it=v[0].begin();it!=v[0].end();it++)
       cout<<*it<<" ";  
       
   cout<<*it<<" ";
   cout<<*(v[0].end());
   it=v[0].begin();

 return 0;
}
