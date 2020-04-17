
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}new;

struct node* insert(struct node* root,int value);
struct node* createnode(int value);
void inorder(struct node* root);

int numberOfLeafNode(struct node* root);
int numberOfNonLeafNode(struct node* root);





struct node* insert(struct node* root,int value)
{
 if(root==NULL)
 {
     root=createnode(value);
 }
 else if(value<=(root->data))
 {
     root->left=insert(root->left,value);
 }
 else
 {
     root->right=insert(root->right,value);
 }
 return root;
}



struct node* createnode(int value)
{
    struct node* temp;
    temp =(struct node*)malloc(sizeof(new));
    temp->data=value;
    temp->right=NULL;
    temp->left=NULL;

    return temp;
}


void inorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}



int numberOfLeafNode(struct node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    else
        return numberOfLeafNode(root->left)+numberOfLeafNode(root->right);
}

int numberOfNonLeafNode(struct node* root)
{
    if(root==NULL)
        return 0;
    if(root->left!=NULL||root->right!=NULL)
        return 1+numberOfNonLeafNode(root->left)+numberOfNonLeafNode(root->right);
}



int main()
{
    struct node* root=createnode(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root,45);
    insert(root,42);


    printf("\ninorder traversal : \n");
    inorder(root);


     int num1=numberOfLeafNode(root);
     printf("\nnumber of leaf node :-%d",num1);

     int num2=numberOfNonLeafNode(root);
     printf("\nnumber of Nonleaf node :-%d",num2);


     return 0;
}
