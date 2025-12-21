#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define MAX_STACKS 10
int s[SIZE];
int boundary[MAX_STACKS];
int top[MAX_STACKS];
int n,i,j,item,ch;

void push()
{
    if(top[i]==boundary[i+1])
    {
        printf("Stack is Full in %d",i);
        return;
    }
    s[++top[i]]=item;
}

void pop()
{
    if(top[i]==boundary[i])
    {
        printf("stack %d is empty",i);
        return;
    }
    printf("Item deleted=%d",s[top[i]--]);
}

void display()
{
    if(top[i]==boundary[i])
    {
        printf("stack %d is empty",i);
        return;
    }
    for(j=boundary[i]+1;j<=top[i];j++)
       printf("%d\n",s[j]);
}

void main()
{
    printf("Enter no of queues\n");
    scanf("%d",&n);
    for(j=0;j<=n;j++)
    {
        boundary[j]=top[j]=SIZE/n*j-1;
    }
    
    for(;;)
    {
        printf("stack Number");
        for(j=0;j<n;j++)
        {
            printf("%d",j);
        }
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
             printf("Enter item");
             scanf("%d",&item);
             push();
             break;

            case 2:
             pop();
             break;

            case 3:
             display();
             break;

            default:
             exit(0);
             
        }
    }
}