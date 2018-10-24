#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}




node * Inersection(node* head1,node* head2)
{
    node *temp1=head1,*temp2=head2,*temp,*head;
    int c=0;
    map<int ,int>m;
    map<int ,int> :: iterator it;
    int val;
    while(temp1)
    {
        val=temp1->data;
            m[val]=1;
        
        
        temp1=temp1->next;
        
    }
    while(temp2)
    {
        val=temp2->data;
        it=m.find(val);
        if(it!=m.end())
        {
            ((*it).second)++;
            
        }
        else
        {
            m[val]=1;
        }
        
        temp2=temp2->next;
        
    }
    
    for(it=m.begin();(it!=m.end())&&((*it).second>1);it++)
    {
        c++;
            if(c==1)
            {
                head=(node* )malloc(sizeof(node));
                head->data=(*it).first;
                head->next=NULL;
                temp=head;
                //temp=temp->next;
            }
            
            else
            {
            temp->next=(node* )malloc(sizeof(node));
                temp=temp->next;
                  temp->data=(*it).first;
                  temp->next=NULL;
            }      
    }
    /*
    for(it=m.begin();(it!=m.end());it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    */
    
    return head;
}


struct node* findIntersection(struct node* head1, struct node* head2)
{
       
    return Inersection(head1,head2);

 
}

int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}

