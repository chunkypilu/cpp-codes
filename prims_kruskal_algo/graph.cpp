class Graph
{
    public:
    int n,no_edges;
    int G[500][500];
        //function to read input text file
    void readInputfile_prim();
    void readInputfile_kruskal();
    //function to print the output
    void printCost();    
};

void Graph :: readInputfile_prim()
{
    ifstream fin;
    fin.open("input_graph.txt");
    if(fin.is_open())
    {
            int x,count=0;
            while (fin >> x) 
                    count++;
                   
            fin.close();
            fin.open("input_graph.txt");
            int i,j;
            n=sqrt(count);
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                   fin>>G[i][j];
                fin.close();
            for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                {
                  //counting no. of nonzero and non -1 elements for getting number of edges
                  if(G[i][j]!=-1&&G[i][j]!=0)
                     no_edges++;
                  if(G[i][j]==-1)
                     G[i][j]=5000;
                }
             no_edges=no_edges/2;
           }
     else
            cout<<"Err opening file";
    }

void Graph :: readInputfile_kruskal()
{
    ifstream fin;
    fin.open("input_graph.txt");
    if(fin.is_open())
    {
            int x,count=0;
            while (fin >> x) 
                    count++;
            fin.close();
            fin.open("input_graph.txt");
            int i,j;
            n=sqrt(count);
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                   fin>>G[i][j];
            fin.close();
            
            for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                  //counting no. of nonzero and non -1 elements for getting number of edges
                  if(G[i][j]!=-1&&G[i][j]!=0)
                    no_edges++;
             no_edges=no_edges/2;
    }
    else
            cout<<"Err opening file";
    }

void Graph:: printCost()
{


        int i,j,cost=0;
        for(i=1;i<=n;i++)
             {
               for(j=1;j<=n;j++)
                {
                  if(G[i][j]!=0&&G[i][j]!=-1)
                    cost+=G[i][j];
                }
                
             }
        cout<<"cost: "<<cost<<")"<<endl;
         for(i=1;i<=n;i++)
             {
               for(j=1;j<=n;j++)
                {
                  if(G[i][j]!=0&&G[i][j]!=-1)
                  {
                    cout<<"("<<i<<","<<j<<")"<<endl;
                  }
                }
               }
}


