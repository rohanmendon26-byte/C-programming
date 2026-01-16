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
        printf("\nMemory is not available:");
        exit(0);
    }
    printf("\nEnter usn,name,branch,phone,sem:");
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
        printf("\nlinked list is empty:");
        return NULL;
    }
    if(start->link==NULL)
    {
        printf("\nThe student node with usn %s is deleted:",start->usn);
        free(start);
        count--;
        return NULL;
    }
    temp=start;
    start=start->link;
    printf("\nThe student with node with usn %s is deleted",temp->usn);
    free(temp);
    count--;
    return start;
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
    NODE prev,cur;
    if(start==NULL)
    {
        printf("\nlinked list is empty:");
        return NULL;
    }
    if(start->link==NULL)
    {
        printf("\nThe student node with usn %s is deleted:",start->usn);
        free(start);
        count--;
        return NULL;
    }
    prev=NULL;
    cur=start;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("\nThe student node with usn %s is deleted",cur->usn);
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
        printf("\nNo contents to display");
        return;
    }
    printf("\ncontents of sll are:");
    cur=start;
    while(cur!=NULL)
    {
        printf("\n||%d||usn:%s|Name:%s|branch:%s|sem:%d|Phone:%ld|",num,cur->usn,cur->name,cur->branch,cur->sem,cur->phone);
        num++;
        cur=cur->link;
    }
}

void stackdemo()
{
    int ch;
    while(1)
    {
        printf("\nStack demo:");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\nEnter your choice:");
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
                return;
        }
    }
    return;
}


void main()
{
    int ch,i,n;
    while(1)
    {
        printf("\n~~~MENU~~~");
        printf("\n1.create a sll of student nodes\n2.insert at end\n3.delete at end\n4.stack demo for insertion and deletion at front\n5.display\n6.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the number of student nodes:");
               scanf("%d",&n);
               for(i=1;i<=n;i++)
               {
                 start=insertfront();
               }
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