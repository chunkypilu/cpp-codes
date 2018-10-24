//dfs of directed graph 0->1 , 0->2 ,2->0, 2->3, 1->2, 3->3
#include<bits/stdc++.h>
using namespace std;


class Graph
{
  int vertices;
  list<int> *adj;
   bool visited[50];
  // for distance
   
  
  
  
  public:
  Graph(int x)
  {
    this->vertices=x;
    adj=new list<int>[vertices];
    memset(visited,false,sizeof(visited));
    
    int dis[vertices][vertices];
    int i,j;
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            dis[][]        
        }
    }
     
  }
  
  void addedge(int u,int v);
  void printadjlist( );
  void dfsfunction(int a);
  void distance(int u, int v);
  
  
};
void Graph:: addedge(int u,int v)
{
    adj[u].push_back(v);


}
void Graph::printadjlist( )
{
    int i;
    list<int > ::iterator it;
    for(i=0;i<vertices;i++)
    {
         for(it=adj[i].begin();it!=adj[i].end();it++)
         {
            cout<<*it<<" ";
         }
         cout<<endl;
    }
    
    
}

void Graph::dfsfunction(int a)
{
    if(!visited[a])
    {
        cout<<a<<" ";
        visited[a]=true;
        
        list<int > :: iterator it;
        for(it= adj[a].begin();it!=adj[a].end();it++)
        {
             if(!visited[*it])
            {
                dfsfunction(*it);
            }
            //cout<<(*it)<<" ";
        }
        
     }
}

void Graph::distance(int u, int v)
{
        
    
    
}


int main()
{

    Graph g(7); 
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(3,0);
    g.addedge(1,0);
    g.addedge(1,2);
    g.addedge(2,1);
    g.addedge(4,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(5,4);
    g.addedge(5,6);
    g.addedge(6,5);
   // g.printadjlist();
   g.dfsfunction(1);
    
    return 0;
}
