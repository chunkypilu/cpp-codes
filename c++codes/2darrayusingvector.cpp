#include<bits/stdc++.h>
using namespace std;
/*
int main()
{
    vector<vector<int> >v;
    vector<int > v1(1,5);
    
    //v1.push_back(1);
    //v1.push_back(2);
    //v1.push_back(3);
    
    v[0].push_back(1);
    
    
    return 0;
}
*/

int main()
 
{
 
// declaring vector of vectors here
 
vector<vector<int> > items;
 
int k;
 
// i value stands for no of rows here(manipulate i as you like)
 
for (int i =0;i<3;i++)
 
{
 
//adding rows of vectors here
 
items.push_back(vector<int>());
 
//inputting each value into a particular of column size 4
 
for (int j=0;j<4;j++){
 cin >> k;
 
items[i].push_back(k);}
 
}
 
//printing out the elements
for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<< items[i][j]<<"\t\t";
			
		}cout<<endl;
    	}
    return 0;
     
    }

