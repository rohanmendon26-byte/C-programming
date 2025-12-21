#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int rear=-1,front=0,count=0;
char item,q[MAX];

void push()
{
    if(count==MAX)
    {
        printf("queue is full");
        return;
    }
    printf("Enter the characters to be inserted:\n");
    scanf(" %c",&item);
    rear=(rear+1)%MAX;
    q[rear]=item;
    count++;
}

void pop()
{
    if(count==0)
    {
        printf("queue is empty:\n");
        return;
    }
    item=q[front];
    front=(front+1)%MAX;
    printf("Item delted is %c",item);
    count--;
}

void display()
{
    int j;
    if(count==0)
    {
        printf("Queue is full:\n");
        return;
    }
    j=front;
    for(int i=1;i<=count;i++)
    {
        printf("%c\n",q[j]);
        j=(j+1)%MAX;
    }
    printf("\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.PUSH\n 2.POP\n3.DISPLAY\n 4.EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            default:
            exit(1);
            break;

        }
    }
}