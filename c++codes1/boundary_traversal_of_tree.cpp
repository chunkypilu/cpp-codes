#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void Printleaves_right(Node*);
void Printleaves_left(Node*);
void Printleft(Node *);
void Printright(Node *);


void Printright(Node *root)
{
    if(root)
    {
        Printright(root->right);
        cout<<root->data<<" ";
        if(root->right==NULL)
        {
            return ;
        }
        //Printright(root->right);
    }
    
}


void Printleft(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        if(root->left==NULL)
        {
            return ;
        }
        Printleft(root->left);
    }
    
}

void Printleaves_left(Node *root)
{
    if(root)
    {
        if((root->right->right==NULL)&&(root->right->left==NULL))
            {cout<<root->right->data<<" ";
             return;
            }
           
            
            
           Printleaves_left(root->left);
            Printleaves_right(root->right);
            Printleaves_left(root->right);
            
    }
}
void Printleaves_right(Node *root)
{
    if(root)
    {
        if((root->left->left==NULL)&&(root->left->right==NULL))
           {
           cout<<root->left->data<<" ";
           return;
           } 
        Printleaves_right(root->left);
        Printleaves_left(root->left);
        
         Printleaves_right(root->right);    
    }
}


void printBoundary(Node* root )
{

    cout<<root->data<<" ";
    Printleft(root->left);
    Printleaves_left(root->left);
    Printleaves_right(root->right);
    Printright(root->right);   



}

Node* newNode(int x)
{
    Node *n=(Node*) malloc(sizeof(Node));
    n->data=x;
    n->right=NULL;
    n->left=NULL;
    return n;
}


int main()
{
    // Let us construct the tree given in the above diagram
    struct Node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->left->right          = newNode(5);
    root->left->left->left    = newNode(2);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    
    
    root->right               = newNode(30);
    root->right->right        = newNode(35);
    root->right->right->right = newNode(38);
     root->right->right->left  = newNode(34);
   
    
    root->right->left         = newNode(25);
    root->right->left->left   = newNode(24);
    root->right->left->right  = newNode(27);
    
    
    printBoundary( root );
 
    return 0;
}

