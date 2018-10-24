#include<bits/stdc++.h>
using namespace std;


// Creating a node (which represents a state)
class node
{
   public:
    string s;
    bool valid;
    bool visited;
    int number;
    node* next;
};

//Structure of graph and related functions
class Graph
{
    public:
        
        vector<node*>v;
        
        void Create_all_nodes( );
        void Print_graph();
        void Print_all_states();
        void Print_path(string);      
};

//Function for creating a node (state)
node* Create_node(int num,string str,bool val)
{
    node* n=new node();
    n->s=str;
    n->number=num;
    n->valid=val;
    n->visited=false;
    n->next=NULL;
    
    return n;
}

//Function for printing all states 
void Graph::Print_all_states()
{
    node *n=Create_node(1,"WCGP0,",true);
    n->next=Create_node(3,"CGP0,W1",true);
    n->next->next=Create_node(4,"WCP0,G1",true);
    n->next->next->next=Create_node(5,"GP0,WC1",true);
    n->next->next->next->next=Create_node(6,",WCGP1",true);
    n->next->next->next->next->next=Create_node(8,"WGP0,C1",true);
    n->next->next->next->next->next->next=Create_node(9,"W0,CGP1",true);
    n->next->next->next->next->next->next->next=Create_node (11,"WC0,GP1",true);
    n->next->next->next->next->next->next->next->next=Create_node(12,"G0,WCP1",true);
    n->next->next->next->next->next->next->next->next->next=Create_node(13,"C0,WGP1",true);
    
    cout<<"\n\nValid states are:\n";
    node* temp=n;
    
    while(temp)
    {
    cout<<temp->number<<"("<<temp->s<<")"<<" ";
    temp=temp->next;
    }
    
    
    n=Create_node(2,"WP0,CG1",false);
    n->next=Create_node(7,"CP0,WG1",false);
    n->next->next=Create_node(10,"CG0,WP1",false);
    n->next->next->next=Create_node    (14,"WG0,CP1",false);
    
    cout<<"\n\nInvalid states are:\n";
    temp=n;
    while(temp)
    {
    cout<<temp->number<<"("<<temp->s<<")"<<" ";
    temp=temp->next;
    }
    
    delete (n);
 }

//Adjacensy list representation of the graph 
void Graph::Create_all_nodes( )
{
  node *n =Create_node(1,"WCGP0,",true);
  n->next=Create_node(10,"CG0,WP1",false);
  n->next->next=Create_node(14,"WG0,CP1",false);
  n->next->next->next=Create_node (11,"WC0,GP1",true);
  v.push_back(n);
  
  n=Create_node(2,"WP0,CG1",false);
  v.push_back(n);
  
  n=Create_node(3,"CGP0,W1",true);
  n->next=Create_node(10,"CG0,WP1",false);
  n->next->next=Create_node(12,"G0,WCP1",true);
  v.push_back(n);
  
  n=Create_node(4,"WCP0,G1",true);
  n->next=Create_node(9,"W0,CGP1",true);
  n->next->next=Create_node(13,"C0,WGP1",true);
  v.push_back(n);  
  
  n=Create_node(5,"GP0,WC1",true);
  n->next=Create_node(6,",WCGP1",true);
  v.push_back(n);  
  
  
  n=Create_node(6,",WCGP1",true);
  v.push_back(n);
  
  n=Create_node(7,"CP0,WG1",false);
  v.push_back(n);
   
  n=Create_node(8,"WGP0,C1",true);
  n->next=Create_node(12,"G0,WCP1",true);
  n->next->next=Create_node    (14,"WG0,CP1",false);
  v.push_back(n);  
  
  n=Create_node(9,"W0,CGP1",true);
  n->next=Create_node(8,"WGP0,C1",true);
  n->next->next=Create_node(2,"WP0,CP1",false);
  v.push_back(n);  
  
  n=Create_node(10,"CG0,WP1",false);
  v.push_back(n);
  
  n=Create_node(11,"WC0,GP1",true);
  n->next=Create_node(4,"WCP0,G1",true);
  v.push_back(n);
  
  n=Create_node(12,"G0,WCP1",true);
  n->next=Create_node(5,"GP0,WC1",true);
  v.push_back(n);
  
  n=Create_node(13,"C0,WGP1",true);
  n->next=Create_node(3,"CGP0,W1",true);
  n->next->next=Create_node    (7,"CP0,WG1",false);
  v.push_back(n);  
  
  n=Create_node(14,"WG0,CP1",false);
  v.push_back(n);
     
}

void Graph::Print_graph()
{
   
  cout<<"\n\n\nOur Graph is:\n"  ;
  vector<node *> ::iterator it;
  
  for(it=v.begin();it!=v.end();it++)
  {
    node *temp=*it;
    while(temp)
    {
        cout<<temp->number<<"("<<temp->s<<")"<<" ";
        temp=temp->next;
    }
   
   cout<<endl; 
  }
  
}


//Function for printing valid paths using BFS
void Graph::Print_path(string s1)
{

    vector<node *>:: iterator it,itr;
    it=v.begin();
    queue <node*> q;
    q.push(*it);
    while(!q.empty())
    {
        it=v.begin();
        node *x=q.front();
        while((x->number)!=((*it)->number))
        {
            it++;
        }
        node *temp=(*it)->next;
        cout<<x->number<<"("<<x->s<<") ";
        
        x->visited=true;
        q.pop();
    
    while(temp)
    {
       if(temp->valid==true)
        {
        
            if(temp->visited==false&&(temp->s!=s1))
            {
                q.push(temp);            
            }
        }  
           temp=temp->next;
          
    }
  }
  cout<<endl<<endl;
}


//Driver function
int main()
{

    int ch;
    Graph g,g1;
    g.Create_all_nodes();
    g1.Create_all_nodes();
    do 
    {
      cout<<"\n\n1.Print complete graph\n2.Print all states\n3.Print path using BFS\n4.Exit\n";
      cin>>ch;
   
        switch(ch)
        {
            case 1:g.Print_graph();
                   break;
            case 2:g.Print_all_states();
                   break;
            case 3:cout<<"\nFirst path is:\n";
                   g.Print_path("C0,WGP1");
                   cout<<"\nAlternative path is:\n";
                   g1.Print_path("W0,CGP1");
                   break;
            case 4:break;
            
            default :cout<<"Invalid choice";break;
        }

    }while(ch!=4);
        
    return 0;
}
