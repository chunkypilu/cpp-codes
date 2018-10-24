#include<bits/stdc++.h>
#include "priorityq.cpp"
#include "mfset.cpp"
#include "graph.cpp"
#include "prim.cpp"
#include "kruskal.cpp"
using namespace std;

int main()
{

    Graph g,g1,g2;
    g.readInputfile_prim();
    g1=prim(g);
    g1.printCost();
    cout<<endl;
    g.readInputfile_kruskal();
    g2=kruskal(g);
    g2.printCost();
    return 0;
}


