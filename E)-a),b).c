#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
}new;

struct node* insert(struct node* root,char value);
struct node* createnode(char value);
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
int height(struct node * root);



struct node* insert(struct node* root,char value)
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



struct node* createnode(char value)
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
    printf("%c\t",root->data);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    inorder(root->right);
    printf("%c\t",root->data);
}

void preorder(struct node* root)
{
    if(root==NULL) return;
    printf("%c\t",root->data);
    inorder(root->left);
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

int totalNumberOfNode(struct node* root)
{
    if(root)
    {
        return 1+totalNumberOfNode(root->left)+totalNumberOfNode(root->right);
    }
    else
        return 0;
}

int height(struct node * root)
{
    int l;
    int r;
    if(root==NULL)
    {
        return 0;
    }
    else
        {
          l=height(root->left);
          r=height(root->right);

          int p=l>r?l:r;


          return (1+p);

        }
}



int main()
{
    struct node* root=createnode('r');
    insert(root,'m');
    insert(root,'t');
    insert(root,'c');
    insert(root,'d');
    insert(root,'o');
    insert(root,'i');
    insert(root,'a');
    insert(root,'z');


    printf("\ninorder traversal : \n");
    inorder(root);

     printf("\npreorder traversal : \n");
     preorder(root);

     printf("\npostorder traversal : \n");
     postorder(root);


      int h= height(root);
      printf("\nheight of tree is: %d",h);

     return 0;
}

