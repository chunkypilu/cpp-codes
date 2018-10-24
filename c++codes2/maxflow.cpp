#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define M 1000

//bool bfs(int parent[ ],int n,vector<vector<int>>& cost)
bool bfs(int parent[ ],int n,int cost[N][M])
{
    int i,j;
    //for(i=1;i<=n;i++)
      //cout<<parent[i]<<" ";
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
   
    queue<int> q;
    q.push(1);
    visited[1]=true;
    
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
       // cout<<"a= "<<a<<" ";
      //  visited[a]=true;
        for(i=1;i<=n;i++)
        {
            if(cost[a][i]!=0&&!visited[i])
            {
                q.push(i);
                parent[i]=a;
                visited[i]=true;
            }
        }
        
    }
     if(parent[n]!=-1)
       return true;
    else
       return false;
}


//int maxflow(vector<vector<int>>& cost,int n,int m)
int maxflow(int cost[N][M],int n,int m)
{
    int i,j,maxflow=0,cp=INT_MAX;
  /*  for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            cout<<cost[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	 */
	 int parent[n];
	 for(i=1;i<=n;i++)
	            parent[i]=-1;
	 
	 int x=0,no=n,a,b;
	 i=0;
	 class node
	 {
	     public:
	     int x1;
	     int y1;
	 };
	 vector<node> v;
	 int k=0;
	 
	 while(bfs(parent,n,cost))
	 {  
	     //k++;
	// cout<<"now";
	 //for(i=1;i<=n;i++)
      //cout<<parent[i]<<" ";
      //cout<<endl;
	    vector<node> v;
	    node n1;
	    //int x=0;
	     while(x!=1)
	     {
	         x=parent[no];
	         n1.x1=x;
	         n1.y1=no;
	         v.push_back(n1);
	         if(cost[x][no]<cp)
	         {
	             cp=cost[x][no];
	             a=x;b=no;
	         }
	         no=x;
	        
	     }
	     x=0;no=n;
	     //cout<<"cp= "<<cp;
	     maxflow+=cp;
	        for(j=0;j<v.size();j++)
	        {
	            cost[v[j].x1][v[j].y1]-=cp;
	            cost[v[j].y1][v[j].x1]+=cp;
	        }
	        cp=INT_MAX;
         
	        for(i=1;i<=n;i++)
	         parent[i]=-1;
	 
	       /*  for(i=1;i<=n;i++)
    	    {
    	        for(j=1;j<=n;j++)
    	        {
    	            cout<<cost[i][j]<<" ";
    	        }
	        cout<<endl;
	    }

	        */
	 }
    return maxflow;
    
}
using namespace std;
int main()
 {
	int t,n,m,x,y,c,i,j;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	   // vector< vector<int> > cost(N, vector<int>(N, 0));
	    int cost[N][M];
	    for(i=0;i<m;i++)
	    {
	        cin>>x>>y>>c;
	        cost[x][y]=c;
	    }
	 /*   for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	        {
	            //cout<<cost[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/
	    cout<<maxflow(cost,n,m)<<endl;
	    
	}
	return 0;
}
