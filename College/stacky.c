#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int s[MAX];
int top=-1;

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("\nStack overflow");
        return;
    }
    printf("\nEnter the item:");
    scanf("%d",&item);
    top++;
    s[top]=item;
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("\nStack underflow");
        return;
    }
    item=s[top];
    top--;
    printf("\nThe item deleted is %d",item);
}

void display()
{
    int item,i;
    if(top==-1)
    {
        printf("\nStack underflow");
        return;
    }
    printf("\nstack contents are:");
    for(i=top;i>=0;i--)\
    {
        printf("%d\t",s[i]);
    }
    printf("\n");
}

void pallindrome()
{
    int i,item,flag=1;
    if(top==-1)
    {
        printf("\nStack underflow");
        return;
    }
    printf("\nstack contents are:");
    for(i=top;i>=0;i--)
       printf("%d\t",s[i]);
    printf("\nStack in reverse order:");
    for(i=0;i<=top;i++)
        printf("%d\n",s[i]);
    for(i=0;i<=top/2;i++)
    {
        if(s[i]!=s[top-i])
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nstack contents are not pallindrome:");
    }
    else
    {
        printf("\nstack contents are pallindrome");
    }
}

void main()
{
    int ch,i;
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Pallindrome\n5.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
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

            case 5:
                exit(0);
        }
    }
}