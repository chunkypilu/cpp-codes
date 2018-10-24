#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    printf("\n\n");
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

 struct Node* addTwoLists (struct Node* first, struct Node* second)
{
    Node *Newlist,*temp1,*temp2,*temp3,*prev,*temp11,*temp22;
  int carry=0,c=0;
  //Newlist=(Node *)malloc(sizeof(Node));
  temp1=first;
  temp2=second;
  
  /*---padding zeros in the smaller list--*/
  while(temp1->next!=NULL||temp2->next!=NULL)
  {
     if(temp1->next==NULL)
        {
            temp11=(Node*)malloc(sizeof(Node));
            temp11->data=0;
            temp11->next=(Node *)NULL;
            temp1->next=temp11;
            //temp1=temp11;
        }
    if(temp2->next==NULL)
        {
            temp22=(Node*)malloc(sizeof(Node));
            temp22->data=0;
            temp22->next=(Node *)NULL;
            temp2->next=temp22;
            //temp1=temp11;
        }    
        temp1=temp1->next;
        temp2=temp2->next;
  }
  
  
  /*---check lists after padding zeros------*/
  
  printf("\nfirst list after padding");
  printList(first);
  printf("\nfirst list after padding");
  printList(second);
  
  temp1=first;
  temp2=second;
  
  
  while(temp1->next!=NULL&&temp2->next!=NULL)
  {   
      c++;
      if(c==1)
      {
            temp3=(Node *)malloc(sizeof(Node));            
            temp3->data=temp1->data+temp2->data+ carry;    
            carry=0;
            if((temp3->data)>=10)
            {
                carry=1;
                temp3->data-=10;
            }
            temp3->next=(Node*)NULL;
            
            Newlist=temp3 ; //this is head of Newlist
            
            prev=temp3;
           // free(temp3);
            //temp3=temp3->next;
      }
      else
      {     temp3=(Node *)malloc(sizeof(Node));
            temp3->data=temp1->data+temp2->data+ carry;  
            
            carry=0;
            
            if((temp3->data)>=10)
            {
                carry=1;
                temp3->data-=10;
            }
            temp3->next=(Node*)NULL;
            prev->next=temp3;
            prev=temp3;
            //free(temp3);
      }
      
      temp1=temp1->next;
      temp2=temp2->next;
            
      
  }
  
  if(temp1->next==NULL&&temp2->next==NULL)
  {
    temp3=(Node*)malloc(sizeof(Node));
    temp3->data=temp1->data+temp2->data+carry;
    carry=0;
    temp3->next=(Node*)NULL;
    prev->next=temp3;
    prev=temp3;
    if((temp3->data)>=10)
    {
        carry=1;
        temp3->data-=10;
        
        
         temp3=(Node*)malloc(sizeof(Node));
         temp3->data=1;
         temp3->next=(Node*)NULL;
         prev->next=temp3;
        
        
    }
  }
  
  
  return Newlist;
}
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}

void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
freeList(first);
freeList(second);
freeList(res);
   }
   return 0;
}


