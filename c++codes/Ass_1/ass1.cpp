#include<bits/stdc++.h>
#define NIL -1
using namespace std;

typedef struct _node
    {
       int value;
       _node* right;
       _node* left;
       _node* up;
       _node* down;
       bool marked;
       int degree;
    } node;
    node *root_head=NULL;  //root_head point to minH in root list


class FibHeap
{
    public:
    int nH;
    int minH;
    
    public:
    //constructor to make a heap
    
    FibHeap()
    {
        nH=0;
        minH=NIL;
    }
    void Concatenate_in_rootlist(node*);
    void FibHeap_insert(FibHeap,int);
    void Print_rootlist( );
    void Create_min_heap_ordered_tree_and_insert();
    //void FibHeap_extract_min(FibHeap);
        
};

void FibHeap::Concatenate_in_rootlist(node *nodex)  //newnode becomes left sibling of the root
{
    
    if(minH==NIL)
        {
        root_head=nodex;
        }
     else
     {
            node *temp=nodex;
        if(root_head->right==root_head&&root_head->left==root_head) //root node only  
        {
              if(nodex->value<root_head->value)
              {
                temp->right=root_head;
                root_head->right=temp;
                temp->left=root_head;
                root_head->left=temp;
                root_head=temp;
              }
              else
              {
                temp->right=root_head;
                root_head->right=temp;
                temp->left=root_head;
                root_head->left=temp;
              }
              
              
              //free(temp);
        } 
        else
        {    
               
                if(nodex->value<root_head->value)  //root_head will always point to minH
                {            
                    temp->right=root_head;
                    temp->left=root_head->left;
                    root_head->left->right=temp;
                    root_head->left=temp;
                    
                    root_head=temp; 
                    //free(temp);
                }
                else
                {
                    temp->right=root_head;
                    temp->left=root_head->left;
                    root_head->left->right=temp;
                    root_head->left=temp;

                    // free(temp);
                }
          
      }   
   }
}

void FibHeap::FibHeap_insert(FibHeap h,int x)
{
        node *newnode = (node*)malloc(sizeof(node));
        newnode->value=x;
        newnode->right=newnode;
        newnode->left=newnode;
        newnode->up=NULL;
        newnode->down=NULL;
        newnode->marked=false;
        newnode->degree=0;
        Concatenate_in_rootlist(newnode);
        if(minH==NIL||x<minH)
        {
            minH=x;
            
        }
        nH++;      
}

void FibHeap::Print_rootlist( )
{
        node* temp =root_head;
        
        if(root_head==NULL)
            cout<<"root list empty"<<endl;
        else
            {    
        do{
            cout<<temp->value<<" ";
            temp=temp->right;
        
        
        }while(temp!=root_head);
            }
            
            cout<<"\nminH="<<minH<<" nH="<<nH<<endl;        
}

node* Create_new_node(int x)
{
    node* node1=(node*)malloc(sizeof(node));
    node1->value=x;
    node1->left=node1;
    node1->right=node1;
    node1->up=NULL;
    node1->down=NULL;
    node1->degree=0;
    node1->marked=false;
    
    return node1;

}

void FibHeap::Create_min_heap_ordered_tree_and_insert()
 {
        
        node* root1=Create_new_node(3);
        root1->down=Create_new_node(52);nH++;    
        root1->down->up=root1;
        root1->down->right=Create_new_node(38);nH++; 
        root1->down->left=Create_new_node(18);nH++;
        
        root1->down->right->right=root1->down->left;
        root1->down->right->left=root1->down;
        root1->down->right->up=root1;
        
        root1->down->left->left=root1->down->right;
        
        root1->down->left->right=root1->down;
        root1->down->left->up=root1;
        root1->down->right->down=Create_new_node(41);nH++;
                        
        root1->down->right->down->up=root1->down->right;
        
        root1->down->left->down=Create_new_node(39);nH++;
        root1->down->left->down->up=root1->down->left;
        Concatenate_in_rootlist(root1);
        if(minH==NIL||3<minH)
        {
            minH=3;
            
        }
        nH++;    
        
          
        
        node* root2=Create_new_node(24);
        
        root2->down=Create_new_node(26);nH++;
        root2->down->up=root2;
        root2->down->right=Create_new_node(46);nH++;
        root2->down->left=root2->down->right;
        
        root2->down->right->left=root2->down;
        root2->down->right->right=root2->down;
        root2->down->right->up=root2;
        
        root2->down->down=Create_new_node(35);nH++;
        root2->down->down->up=root2->down;
        Concatenate_in_rootlist(root2);
        if(minH==NIL||24<minH)
        {
            minH=24;
            
        }
        nH++; 
        
        
        
        node* root3=Create_new_node(17);
        root3->down=Create_new_node(30);nH++;
        root3->down->up=root3;
        Concatenate_in_rootlist(root3);
        if(minH==NIL||17<minH)
        {
            minH=17;
            
        }
        nH++;
        
        
 } 
 
 
 void swap(node *x,node *y)
{
//    node *a,*b,*c,*d,*e,*f,*g,*h;
//    a=x->right;
//    b=x->left;
//    c=a->left;
//    d=b->right;
//    
//    e=y->right;
//    f=y->left;
//    g=e->left;
//    h=f->right;

//    
//    
//    y->right=a;
//    y->left=b;
//    c=y;
//    d=y;
//    
//    x->right=e;
//    x->left=f;
//    g=x;
//    h=x;

        node* temp=Create_new_node(NIL);
        
        temp->value=x->value;
        temp->up=x->up;
        temp->down=x->down;
        temp->degree=x->degree;
        temp->marked=x->marked;
    
        x->value=y->value;
        x->up=y->up;
        x->down=y->down;
        x->degree=y->degree;
        x->marked=y->marked;
        
        y->value=temp->value;
        y->up=temp->up;
        y->down=temp->down;
        y->degree=temp->degree;
        y->marked= temp->marked;
        
        root_head=x;  //because x is small now
        
        node* z;
        z=x;
        x=y;
        y=z;
        
                
        free(temp);
        
    }
 
void FibHeap_link(FibHeap h,node *y,node *x)
{
    node *a;
    //remove y from root list
    y->left->right=y->right;
    y->right->left=y->left;
    
    
    y->left=y;
    y->right=y;
    
    if(x->down==NULL)
    {
        x->down=y;
        y->up=x;
    }
    else
    {
        a=x->down->right;  
        y->right=x->down->right;
        y->left=x->down->right->left;
        x->down->right=y;
        a->left=y;
        
   }
   y->marked=false;
   
   
//   cout<<"root->down="<<root_head->down->value<<endl;
//   cout<<"root->down->right="<<root_head->down->right->value<<endl;
//   cout<<"root->down->right->right="<<root_head->down->right->right->value<<endl;
//   cout<<"root->down->right->right->right="<<x->down->right->right->right->value<<endl;
//   cout<<"root->down->right->right->right>right="<<x->down->right->right->right->right->value<<endl; 
}      
 
 /*----Consolidate function----------------*/
 void Consolidate(FibHeap h)
 {
    int size=floor((log(h.nH))/log(2)),d,i;
    node* arr[size+1],*y;
    
    for(i=0;i<=size;i++)
        arr[i]=NULL;
    
    node* x=root_head;    
    do{
        
        
        d=x->degree;
        
            while(arr[d]!=NULL)
            {
                y=arr[d];
                
               if(x->value>y->value)
                {
                    swap(x,y);
                }
               
                FibHeap_link(h,y,x);
                arr[d]=NULL;
                d++; 
            }
        
        arr[d]=x;
        x=x->right;
    }while(x!=root_head);
    
   // h.minH=NIL;
     root_head->value=NIL;   
    node *a;    
    for(i=0;i<=size;i++)
    {
        if(arr[i]!=NULL)
            {
                a=root_head->left;
                arr[i]->left=root_head->left;
                arr[i]->right=root_head->left->right;
                root_head->left=arr[i];
                a->right=arr[i];    
                
                if(h.minH== NIL||((arr[i]->value)<(root_head->value)))
                {
                    root_head=arr[i];
                }
            }
    }    
    
 }
 
 
 node* FibHeap_extract_min(FibHeap h)
 {
    node *z=NULL;
    node *a,*b,*x,*temp,*old_root;
    z=root_head;
    old_root=z;
    
    if(root_head->down!=NULL)
    if(z!=NULL)
    {
        a=z->down;
        x=a;
        b=a->right;
        do{
            temp=a;
            (z->left)->right=temp;
            temp->left=z->left;
            z->left=temp;
            temp->right=z;
            temp->up=NULL;
            z=z->left;
            a=b;
            b=b->right;
        
        }while(a!=x);
        //removing z from list (root list in our case )
        (root_head->left)->right=root_head->right;
        (root_head->right)->left=root_head->left;
        
        if(root_head->right==root_head)
        {
                root_head=  NULL;
        }
        else
        {
            root_head=root_head->right;
            Consolidate(h);
        }
        h.nH--;
        
        }
    return old_root;    
    
 }
 



int main()
{
    FibHeap h;
    int ch,val;
    node *x;
    
    do{
    cout<<"\n1.Insert\n2.Extract min\n3.Decrease key\n4.1delete a node\n5.Print root list\n6.Create min heaps ordered tree (same as book (of root 3,17,24)) and insert\n7.Exit\n";
    cin>>ch;
    switch(ch)
    {
    case 1:  cout<<"Enter key to be inserted\n";
             cin>>val;
             h.FibHeap_insert(h,val); break;
             
    case 2:  cout<<"2\n"; //Consolidate(h);
             //swap(root_head,root_head->right->right);
             //FibHeap_link(h,root_head->right,root_head);
             x=FibHeap_extract_min(h);
             cout<<"Extracted min val="<<x->value<<endl;
             break;
    case 3:  cout<<"3\n"; break;
    case 4:  cout<<"4\n"; break;
    case 5:  h.Print_rootlist(); break;
    case 6:  h.Create_min_heap_ordered_tree_and_insert(); break;
    case 7:  cout<<"7\n"; break;
    default: cout<<"Invalid choice\n"; break;
    }
    }while(ch!=7); 
    
    cout<<"hello";
    
    return 0;
}
