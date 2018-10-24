
Graph kruskal(Graph g)
{
    int start_s=clock();
    Graph g2;
    g2.n=g.n;
    int i,j,k;
    char ch='a'; 
    for(i=1;i<=g2.n;i++)
    {
       INITIAL(ch,i);
       ch=ch+1;
    }
    for(i=1;i<=g.n;i++)
             {
               for(j=1;j<=g.n;j++)
                {
                  if(g.G[i][j]!=0&&g.G[i][j]!=-1)
                  {
                     if(i<j)
                       INSERT(i,j,g.G[i][j]);
                  }
                }
             }
    
    
    for(i=1;i<=g2.n;i++)
             {
               for(j=1;j<=g2.n;j++)
                {
                  g2.G[i][j]=-1;
                  
                }
            }
    node q_node;
    
    int x=g2.n;
     while(x>1)
     {
        q_node=DELETEMIN();
        
        if(FIND(q_node.u)!=FIND(q_node.v))
        {
          MERGE(q_node.u,q_node.v);
          g2.G[q_node.u][q_node.v]=g.G[q_node.u][q_node.v];
          x--;
        }
     }

    int stop_s=clock();
   cout<<"Kruskal's algorithm MST  (runtime: "<<((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000<<"ms,";
   return g2;
}


