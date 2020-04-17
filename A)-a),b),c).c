#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node * link;
}new;

struct node * head;
void create(int n);
void traversal();
void deleteAtBegining();
void deleteAtEnd();
void deleteAtAny();

void create(int n)
{
    struct node * temp,*newnode;
    int x;
    head=(struct node*)malloc(sizeof(new));
    temp=head;
    printf("enter 1st node data :-");
    scanf("%d",&x);
    head->data=x;
    head->link=NULL;

    for(int i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(new));
        printf("enter node data :-");
        scanf("%d",&x);
        newnode->data=x;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }

}

void traversal()
{
    struct node * temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;

    }
}



void deleteAtAny()
{
    struct node * temp1, * temp2, *temp3;
    int pre,next,cur;
    printf("enter deletion data :-");
    scanf("%d",&cur);
    printf("enter previous data :-");
    scanf("%d",&pre);
    printf("enter next data  :-");
    scanf("%d",&next);
    temp1=head;
    temp2=head;

    while(temp1->data!=pre)
    {
        temp1=temp1->link;
    }
     while(temp2->data!=next)
    {
        temp2=temp2->link;
    }
    while(temp3->data!=cur)
    {
        temp3=temp3->link;
    }
    temp1->link=temp2;
    free(temp3);
    temp3=NULL;
     printf("updated list\n");
     traversal();

}
void deleteAtBegining()
{
    struct node * temp;
    temp=head;
    if(head==NULL)
    {
        printf("their is no node available to delete");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        head=head->link;
        free(temp);
        temp=NULL;
        printf("updated list\n");
        traversal();
    }
}

void deleteAtEnd()
{
    struct node *temp=head;
    while(temp->link->link!=NULL)
   {
     temp=temp->link;
   }
    temp->link=NULL;
    free(temp->link);
   // temp->link=NULL;
   printf("updated list\n");
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
     deleteAtBegining();
     deleteAtEnd();
     return 0;
}
