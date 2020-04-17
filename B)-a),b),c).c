#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;

}new;
struct node* head;
void create(int n)
{
    struct node * temp;
    int x,y;

    head=(struct node *)malloc(sizeof(new));
    printf("enter 1st data :");
    scanf("%d",&x);
    temp=head;
    head->data=x;
    head->left=NULL;
    head->right=NULL;


    for(int j=1;j<n;j++)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(new));
        printf("enter data :");
        scanf("%d",&y);
        newnode->data=y;
        newnode->right=NULL;
        newnode->left=temp;
        temp->right=newnode;
        temp=temp->right;
    }

}

void traversal()
{
    struct node * temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->right;
    }
}



void deleteAtAny()
{
    struct node* temp1,* temp2;
    temp1=head;
    temp2=head;
    int pre,next,cur;
    printf("enter deletion data :-");
    scanf("%d",&cur);
    printf("enter previous data :-");
    scanf("%d",&pre);
    printf("enter next data  :-");
    scanf("%d",&next);

    while(temp1->data!=pre)
    {
        temp1=temp1->right;
    }

     while(temp2->data!=next)
    {
        temp2=temp2->right;
    }
    temp1->right=temp2;
    temp2->left=temp1;
    printf("\nupdated data after deletion from end\n");
    traversal();
}

void deleteAtBeginning()
{
    struct node* temp;
    temp=head;
    head=head->right;
    free(temp);
    temp->right=NULL;
    printf("\nupdated data after deletion from beginning\n");
    traversal();
}

void deleteAtEnd()
{
    struct node * temp,*temp2;
    temp=head;
    while(temp->right->right!=NULL)
    {
        temp=temp->right;
    }
    while(temp2->right!=NULL)
    {
        temp2=temp2->right;
    }
    temp->right=NULL;
    temp2->left=NULL;
    free(temp2);
    printf("\nupdated data after deletion from end\n");
    traversal();
}
int main()
{
    int n;
     printf("enter no of nodes :-");
     scanf("%d",&n);
     create(n);
     traversal();


     deleteAtAny();
     deleteAtBeginning();
     deleteAtEnd();

     return 0;
}


