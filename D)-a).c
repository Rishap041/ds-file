#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void insertAtBeginning()
{
    if(front==0)
    {
        printf("no space is available at front side\n");
    }
    else if(rear==-1&&front==-1)
    {
        int value;
    printf("enter value which u inserted :-");
    scanf("%d",&value);
        front++;
        rear++;
        queue[rear]=value;
    }
    else
    {
        int value;
    printf("enter value which u inserted :-");
    scanf("%d",&value);
        front--;
        queue[front]=value;
    }
}

void insertAtEnd()
{
     if(rear==MAX-1)
    {
        printf("overflow");
    }
    else if(rear==-1&&front==-1)
    {
        int value;
    printf("enter value which u inserted :-");
    scanf("%d",&value);
        front++;
        rear++;
        queue[rear]=value;
    }
    else
    {
        int value;
    printf("enter value which u inserted :-");
    scanf("%d",&value);
        rear++;
        queue[rear]=value;
    }
}

void deleteAtFront()
{
    if(front==-1)
    {
        printf("underflow\n");
    }

    else if(rear==front)
    {
        printf("deleted element  :-%d\n",queue[front]);
        front=-1;
        rear=-1;
    }

    else
    {
        printf("deleted element  :-%d\n",queue[front]);
        front++;
    }
}


void deleteAtEnd()
{
    if(front==-1)
    {
        printf("underflow\n");
    }

     else if(rear==front)
    {
        printf("deleted element  :-%d",queue[rear]);
        front=-1;
        rear=-1;
    }

     else
    {
        printf("deleted element  :-%d",queue[rear]);
        rear--;
    }
}

void display()
{
    int i;
 if (front == - 1)
    printf("Queue is empty \n");

 else
 {
    printf("Queue is : \n");
    for (i = front; i <= rear; i++)
    printf("%d ", queue[i]);
    printf("\n");
 }
}
int main()
{


    int choice;
 while (1)
 {
 printf("1.Insert element to queue at front \n");
 printf("2.Insert element to queue at end \n");
 printf("3.Delete element from queue at front \n");
 printf("4.Delete element from queue at end\n");
 printf("5.Display all elements of queue \n");
 printf("6.Quit \n");
 printf("Enter your choice : ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 insertAtBeginning();
 break;
 case 2:
 insertAtEnd();
 break;
 case 3:
 deleteAtFront();
 break;
 case 4:
 deleteAtEnd();
 break;
 case 5:
 display();
 break;
 case 6:
 exit(1);
 default:
 printf("Wrong choice \n");
 }
 }
 return 0;
}


