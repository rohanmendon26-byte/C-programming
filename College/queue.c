#include<stdio.h>
#include<stdlib.h>
#define MAX 3
char rear=-1,front=0,count=0;
char item,q[MAX];

void insertqueue()
{
    if(count==MAX)
    {
        printf("\nQueue underflow");
        return;
    }
    printf("\nEnter the characters to be inserted:");
    scanf("%c",&item);
    rear=(rear+1)%MAX;
    q[rear]=item;
    count++;
}

void deletequeue()
{
    if(count==0)
    {
        printf("\nQueue overflow");
    }
    item=q[front];
    front=(front +1)%MAX;
    printf("\nThe deleted item is %c",item);
    count--;
}

void display()
{
    int i,j;
    if(count==0)
    {
        printf("\nQueue overflow");
    }
    j=front;
    for(i=1;i<=count;i++)
    {
        printf("\n %c",q[j]);
        j=(j+1)%MAX;
    }
    printf("\n");
}


void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insertqueue\n2.DeleteQueue\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
            case 1:
               insertqueue();
               break;

            case 2:
               deletequeue();
               break;

            case 3:
                display();
                break;

            case 4:
                 exit(0);
        }
    }
}