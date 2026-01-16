#include<Stdio.h>
#include<stdlib.h>
#define MAX 3
int s[MAX];
int top=-1;

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("\nstack overflow\n");
    }
    printf("\nEnter the item:\n");
    scanf("%d",&item);
    top++;
    s[top]=item;
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("\nstack underflow\n");
    }
    item=s[top];
    top--;
    printf("\nItem deleted is %d\n",item);
}

void display()
{
    int item,i;
    if(top==-1)
    {
        printf("\nstack underflow\n");
    }
    printf("\nstack contents are\n");
    for(i=top;i>=0;i--)
    {
        printf("|%d|\t",s[i]);
    }
    printf("\n");
}


void pallindrome()
{
    int item,flag=1,i;
    if(top==-1)
    {
        printf("\nstack underflow\n");
    }
    printf("\nstack contents are\n");
    for(i=top;i>=0;i--)
        printf("|%d|\t",s[i]);
    printf("\nstack contents in reverse order are:\n");
    for(i=0;i<=top;i++)
        printf("|%d|\n",s[i]);
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
        printf("Stack contents aare pallindrome\n");
    }
    else
    {
        printf("stack contents are not pallindrome\n");
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PALLINDROME\n5.EXIT\n");
        printf("Enter your choice\n");
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

            case 5:
               exit(0);

        }
    }
}