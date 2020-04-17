#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*front,*rear;

typedef struct node Node;

void createfirstnode() //Creates first node
{
     int data;
     front=(Node*)malloc(sizeof(Node));
     if(front==NULL)
     {
         printf("Memory not allocated");
         return;
     }
     printf("\nEnter node data : ");
     scanf("%d",&data);
     front->data=data;
     front->prev=NULL;
     front->next=NULL;
     rear=front;
}

void insertFromFront() //Inserts from Front
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=front;
    temp->prev=NULL;
    front=temp;
}

void insertFromRear() //Inserts from Rear
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=rear;
    rear->next=temp;
}

void deleteFromFront() //Deletes from Front
{
    if(front==NULL)
    {
        printf("\nDeque is empty !!!");
        return ;
    }
    Node *temp=front;
    front=temp->next;
    free(temp);
}

void deleteFromRear() //Deletes from Rear
{
    if(rear==NULL)
    {
        printf("\nDeque is empty !!!");
        return ;
    }
    Node *temp=rear;
    rear=temp->prev;
    free(temp);
}

void traverse()     //Traverses the list
{
	Node *temp=front;
    printf("\nYour list is : ");
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main() //Driver Function
{
	int res=0;
    while(1)
    {
        printf("\nPress \n'1' to insert from front\n'2' to delete from front\n'3' to insert from rear\n'4' to delete from rear\n'5' to traverse the list\n'6' if you wanna exit\n");
        scanf("%d",&res);
        switch(res)
        {
            case 1 : insertFromFront();
                     break;

            case 2 : deleteFromFront();
                     break;

            case 3 : insertFromRear();
                     break;

            case 4 : deleteFromRear();
                     break;

            case 5 : traverse();
                     break;

            case 6 : exit(1);

            default : printf("\nYou entered wrong choice !!!!!!!!!!!!");
                      break;
        }
    }
return 0;
}
