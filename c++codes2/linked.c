/* --- subroutines for a linked list --- */

typedef struct _NODE
	{
	int data;
	struct _NODE * next;
	} NODE;

/* --- function declarations --- */
NODE * get_node(int value);
void print_list(NODE *head);

/* --- function definitions --- */
NODE * get_node(int value)
{
NODE * p;
p = (NODE *) malloc (sizeof(NODE));

p->data = value;
p->next = (NODE *) NULL;
return p;
}


void print_list(NODE *head)
{
NODE *p;

for(p = head; p != (NODE *) NULL; p = p->next)
{ /* for each node in the linked list */
printf("node has data = %d\n",p->data);
} /* for each node in the linked list */

return;
}
