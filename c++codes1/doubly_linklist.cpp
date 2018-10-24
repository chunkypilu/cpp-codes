#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
 struct Node* newNode(struct Node* head,int data){
	 struct Node *p,*temp= (struct Node*)malloc(sizeof(struct Node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 if(head ==NULL)
	 return temp;
	 p=head;
	 while(p->next!=NULL){
	 p=p->next;}
	 p->next=temp;
	 temp->prev=p;
	 return head;
	 }
/* Function to reverse a Doubly Linked List */
void addNode(struct Node **head_ref,int pos,int data)
{
    //cout<<"heloo"<<" ";
   struct Node *temp;
   temp=*head_ref;
   int i;
   for(i=0;i<pos;i++)
   {
       temp=temp->next;
   }
   //cout<<temp->data<<" "<<endl;
  
   struct Node *new_node= (Node *)malloc(sizeof(Node));
   
   if(temp->next==NULL)
   {
        new_node->data=data;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
   }
   
   else
   {
       struct Node *t=temp->next;
       new_node->data=data;
       temp->next=new_node;
       new_node->prev=temp;
       new_node->next=t;
       t->prev=temp;
   }
    
}



void printList(struct Node *Node)
{
  struct Node *temp=Node;
  //goto end
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }

  //goto start
  while(temp->prev!=NULL)
  {
   temp = temp->prev;
  }

  //now print
  while(temp!=NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  printf("\n");
}
 int main()
{
  int t,x,n,i;
  scanf("%d",&t);
  while(t--)
  {
  /* Start with the empty list */
  struct Node *temp,*head = NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&x);
  head=newNode(head, x);
  }
  int pos,data;
  cin>>pos>>data;
  addNode(&head,pos,data);
  printList(head);
  while(head->next!=NULL)
  {
	  temp=head;
	  head=head->next;
	  free(temp);
	  }
	}
	return 0;
}

