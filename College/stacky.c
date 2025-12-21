#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int top=-1;
int s[MAX];

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
    }
    printf("Enter the item:\n");
    scanf("%d",&item);
    top++;
    s[top]=item;
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack underflow:\n");
    }
    item=s[top];
    top--;
    printf("Item deleted is %d\n",item);
}


void display()
{
    int item,i;
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    printf("stack contents are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
    printf("\n");
}

void pallindrome()
{
    int flag=1,item,i;
    if(top==-1)
    {
        printf("stack underflow:\n");
    }
    printf("stacks contents are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
    printf("stacks in reverse:\n");
    for(i=0;i<=top;i++)
        {
            printf("%d\n",s[i]);
        }
    for(i=0;i<=top/2;i++)
    {
        if(s[i]!=s[top-i])
        {
            flag=0;
            break;
        }
    }

    if(flag==1)
    {
        printf("Stack contents are pallindrome\n");
    }
    else
    {
        printf("stack contents are not pallindrone:\n");
    }  
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PALLINDROME\n5.EXIT\n");
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

            case 4:
            pallindrome();
            break;

            default:
            exit(0);
        }
    }
}