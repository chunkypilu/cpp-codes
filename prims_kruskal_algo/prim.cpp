Graph prim(Graph g)
{
  int start_s=clock();
   Graph g1;
   g1.n=g.n;
   
    int i,j,k,min;
      int LOWCOST[g.n],CLOSEST[g.n];
      for(i=2;(i<=g.n);i++)
      {
            LOWCOST[i]=g.G[1][i];
            CLOSEST[i]=1;
      }
                 
      for(i=2;i<=g.n;i++)
      {
            min=LOWCOST[2];
            k=2;
            for(j=3;j<=g.n;j++)
            {
                if(LOWCOST[j]<min)
                {
                    min=LOWCOST[j];
                    k=j;
                }
            }
            g1.G[k][CLOSEST[k]]=min;
            LOWCOST[k]=20000; //large number
            
            for(j=2;j<=g.n;j++)
            {
                if((g.G[k][j]<LOWCOST[j])&&(LOWCOST[j]<20000))
                {
                    LOWCOST[j]=g.G[k][j];
                    CLOSEST[j]=k;
                }
            }
      }
   int stop_s=clock();
   cout<<"Prim's algorithm MST  (runtime: "<<((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000<<"ms,";
   return g1;
}



