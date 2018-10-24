#include<stdio.h>
#include<stdlib.h>

typedef struct _NODE
 {
    int data;
    struct _NODE *ptr;
 } NODE;

    NODE *head,*current, *temp,*temp1;
    int x=0;
    
    
int sizeOflist(NODE* head)
{
    int i=0;
    temp=head;
    while(temp->ptr!=NULL)
    {
        i++;
        temp=temp->ptr;
    }
    return i+1;
}    
    

/*---Delete a node with given value--*/
void deleteNodeofgivenvalue(int value)
{
    temp=head;
    while(temp->ptr!=(NODE *)NULL)
    {
    
        if(head->data==value )
        {
            
            head->ptr=(NODE *)NULL;
            head=temp;
            break;       
        }
        
        else
        {
            if(temp->data==value)
            {
                temp1->ptr=temp->ptr;
                temp->ptr=(NODE* )NULL;
                break;
                
            }
            temp1=temp;
            
        }
        temp=temp->ptr;
    }
        
    
}    
    
    
    
/*-------insert after a node----------*/
void insertAfter(int value, int n)
{
    temp=(NODE *)malloc(sizeof( NODE));
    temp->data=value;
    temp->ptr=(NODE *)NULL;
    
    temp1=head;
    while(temp1!=(NODE *)NULL)
    {
        if((temp1->data)==n)
        {
            temp->ptr=temp1->ptr;
            temp1->ptr=temp;
            break;
        }
        
        temp1=temp1->ptr;
                
    }
        
}    
    
    
    
    
/*-------insert node at last-------*/
void insertatLast(int value)
{
    temp=(NODE *)malloc(sizeof( NODE));
    temp->data=value;
    temp->ptr=(NODE *)NULL;
    current->ptr=temp;
    current=temp;
}








/*--------insert node at front---------------------*/
void insertNodeatfront(int value)
{
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=value;
    temp->ptr=head;
    head=temp;
    //free(temp);
    
}





void createNODE(int value)
{
    x++;
    if(x==1)
    {
        head=(NODE *)malloc(sizeof( NODE));
        head->data=value;
        head->ptr=(NODE *)NULL;
        current=head;
        //printf("%d",current->data);
    }
    else
    {   
        temp=(NODE *)malloc(sizeof(NODE));
        temp->data=value;
        temp->ptr=(NODE *)NULL;
        current->ptr=temp;
        current=temp;
        //free(temp);
        //printf("%d",current->data);
    }
    
}

void printNode(NODE *head)
{
    temp=head;
    while(temp!=(NODE *)NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->ptr;        
    }
    
    printf("\n");
}




int main()
{
    /*-------creating 5 nodes with values 1....5 ---------*/
    int i;
    for(i=1;i<=5;i++)
    {
        createNODE(i);
    }
    printNode(head);
    
    /*-------inserting a node with value 10--------*/
    // insertNodeatfront(10);
    /*-------printing node-------------*/
    /*-------insert node at last---------*/  
    insertatLast(25);
    /*--------inserting 89 after 5----------*/
   // insertAfter(89,3);   
    printNode(head);
    
    /*----delete a node of value 3---------*/
    //deleteNodeofgivenvalue(89);
    //printNode(head);
    /*-----length of link list------------*/
    printf("length=%d",sizeOflist(head));
    
    
    return 0;
}
