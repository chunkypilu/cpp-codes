#include<bits/stdc++.h>
using namespace std;

/*
void printlist(vector<int> *v,int N)
{
    int i,j;
    for (i=0;i<N;i++)
	    {
	        for(j=0;j<v[i].size();j++)
	        {
	           cout<<v[i][j]<<" ";  
	        }
	        cout<<endl;
	        
	    }
	    
}

*/

void answer(vector<int> *v,int N)
{   //DFS to traverse the graph
    bool visited[N];
    int i;
    for(i=0;i<N;i++)
       visited[i]=false;
    map<int,int> m;
    stack<int> s;
    visited[0]=true;
    s.push(0);
    cout<<"0"<<endl;
    vector<int>:: iterator it;
    //cout<<__LINE__;

    it=v[0].begin();
    
    //cout<<*it<<"hello";
    //it++;
    // cout<<__LINE__;
    while(!s.empty())
    {   

        int a=*it;
        while(visited[*it]==true&&(it!=1000))
        {
          it++;
          
        }
        
        
        
        
        if(visited[*it]==false)
          {
              visited[a]=true;
              cout<<a<<" ";
              s.push(a);
              
              it=v[a].begin();
             // continue;              
          }   
              if(it==v[a].end())
              {
                  int x=s.top();
                  cout<<"x= "<<x<<endl;
                  s.pop();
                  it=v[x].begin();
              }       
    }
    
}



int main()
 {
  
    freopen("input.in","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
	    int N,x,y,i;
	    cin>>N;
	    vector<int> v1,v[N];
	    for(i=0;i<N-1;i++)
	    {
	        cin>>x;
	        cin>>y;
	        v[x-1].push_back(y-1);
	        v[y-1].push_back(x-1);
	        
	    }
	    
	    //cout<<v;

	    for (i=0;i<N;i++)
	    {
	        //for(j=0;j<v[i].size();j++)
	        
	           v[i].push_back(1000);  
	        
	       // cout<<endl;
	        
	    }
	   //printlist(v,N);
	  answer(v,N);
	    
	}
	return 0;
}
