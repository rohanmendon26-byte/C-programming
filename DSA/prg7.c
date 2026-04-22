#include<stdio.h>
#include<stdlib.h>
 

struct node
{
    char usn[25],name[25],branch[25];
    int sem;
    long int phone;
    struct node *link;
};

typedef struct node *NODE;
NODE start=NULL;
int count=0;

NODE create()
{
    NODE snode;
    snode=(struct node *)malloc(sizeof(struct node));
    if(snode==NULL)
    {
        printf("\nMemory is unavailable");
        exit(0);
    }
    printf("\nEnter your USN,Name,Branch,sem and phone:");
    scanf("%s %s %s %d %ld",snode->usn,snode->name,snode->branch,&snode->sem,&snode->phone);
    snode->link=NULL;
    count++;
    return snode;
}

NODE insertfront()
{
    NODE temp;
    temp=create();
    if(start==NULL)
    {
        return temp;
    }
    temp->link=start;
    return temp;
}

NODE deletefront()
{
    NODE temp;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }
    if(start->link==NULL)
    {
        printf("\nThe student with usn %s is deleted",start->usn);
        count--;
        free(start);
        return NULL;
    }
}

NODE insertend()
{
    NODE temp,cur;
    temp=create();
    if(start==NULL)
    {
        return temp;
    }
    cur=start;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return start;
}

NODE deleteend()
{
    NODE cur,prev;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }

    if(start->link==NULL)
    {
        printf("\nThe student with usn %s is deleted",start->usn);
        count--;
        free(start);
        return NULL;
    }
    prev=NULL;
    cur=start;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("\nThe student with usn %s is deleted",cur->usn);
    free(cur);
    count--;
    prev->link=NULL;
    return start;
}

void display()
{
    NODE cur;
    int num=1;
    if(start==NULL)
    {
        printf("\nNo item to display");
        return;
    }
    cur=start;
    while(cur!=NULL)
    {
        printf("\n||%d||%s|%s|%s|%d|%ld|",num,cur->usn,cur->name,cur->branch,cur->sem,cur->phone);
        num++;
        cur=cur->link;
    }
    printf("\nTotal number of students:%d",count);
}

void stackdemo()
{
    int ch,n;
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               start=insertfront();
               break;

            case 2:
               start=deletefront();
               break;

            case 3:
               display();
               break;

            case 4:
                exit(0);
        }
    }
}

int main()
{
    int ch,i,n;
    while(1)
    {
        printf("\n~~~MENU~~~");
        printf("\n1.create a sll\n2.insertend\n3.deleteend\n4.stackoperation\n5.display\n6.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the  number of students:");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
               start=insertfront();
               break;
               
            case 2:
               start=insertend();
               break;

            case 3:
               start=deleteend();
               break;

            case 4:
               stackdemo();
               break;

            case 5:
               display();
               break;
            
            case 6:
               exit(0);
        }
    }
}