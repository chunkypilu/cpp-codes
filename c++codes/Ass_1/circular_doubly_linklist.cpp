#include<bits/stdc++.h>
using namespace std;

typedef struct _node
{
    int val;
    _node *right;
    _node *left;
}node;

root=NULL;


void Inser(int x)
{

    node *newnode=(node)malloc(sizeof(node));
    newnode->val=x;
    newnode->right=newnode;
    newnode->left=newnode;
    
    if(root==NULL)
    {
        root=newnode;    
    }
    else
    {
        newnode->right=root;
        newnode->left=root->left;
        root->left->right=newnode;
        root->left=newnode;
    }
    
}

void Print()
{
    node* temp
}

int main()
{

   



    return 0;
}
