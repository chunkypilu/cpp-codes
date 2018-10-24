#include<bits/stdc++.h>
using namespace std;

int front=-1, rear=-1;

class node
{
    public:
    int u,v,val;
};

node n[500];
node DELETEMIN()
{ 
    int i;
    if(front==-1&&rear==-1)
    {  
       cout<<"Q is empty";
       return n[0];
    }
    else if(front==0&&rear==0)
    {
         int x=front;
          front--;
          rear--;
          return n[x];
          
    }
    else{
          node del_node=n[0];
        for(i=0;i<rear;i++)
                n[i]=n[i+1];
           rear--;
           return del_node;
        }
}

void INSERT(int i,int j, int value)
{
    
     node n1;
     n1.u=i;
     n1.v=j;
     n1.val=value;
    if(front==-1&&rear==-1)
    {
      front++;
      rear++;
      n[rear]=n1;
    }
    
    else
    {
          if(value>=n[rear].val)
              n[++rear]=n1;
          else
          {
            for(i=rear;i>=front&&n[i].val>value;i--);
            for(j=rear+1;j>=i+2;j--)
                n[j]=n[j-1];
            rear++;
            n[i+1]=n1;
          }
    }
    
}

void printqueue()
{

int x;
   for(x=0;x<=rear;x++)  //front is maintained at 0 always
    {
        cout<<n[x].val<<" ";
    }
    
}
////cd /media/priyank/New\ Volume/M\ Tech/ctech/3rd\ SEM/ELL781/Assignment3
