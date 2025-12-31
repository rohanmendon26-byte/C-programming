#include<stdio.h>
#include<stdlib.h>

struct node{
    char name[25],usn[25],branch[25];
    int sem;
    long int phone;
    struct node * link;
};

typedef struct node*NODE;
NODE start=NULL;
int count=0;

NODE create()
{
    NODE snode;
    snode=(struct node*)malloc(sizeof(struct node));
    if(snode==NULL){
        printf("\nMemory is not available:\n");
    }
    printf("\nEnter the name,usn,branch,sem,phone\n");
    scanf("%s %s %s %d %ld",snode->name,snode->usn,snode->branch,&snode->sem,&snode->phone);
    snode->link=NULL;
    count++;
    return snode;
}

NODE insertfront()
{
    NODE temp;
    temp=create();
    if(start==NULL){
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
        printf("\n The list is empty:\n");
        return NULL;
    }
    if(start->link==NULL)
    {
        printf("\nThe student with usn %s is deleted\n",start->usn);
        count--;
        free(start);
        return NULL;
    }
    temp=start;
    start=start->link;
    printf("\nThe student with usn %s is deleted:\n",temp->usn);
    count--;
    free(temp);
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
        printf("\nThe list is empty\n");
        return NULL;
    }

    if(start->link==NULL)
    {
        printf("\nThe student with usn %s is deleted\n",start->usn);
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
    printf("\n The student with usn %s is deleted\n",cur->usn);
    prev->link=NULL;
    count--;
    free(cur);
    return start;
}

NODE display()
{
    NODE cur;
    int num=1;
    if(start==NULL)
    {
        printf("\nNo items to display return\n");
        return 0;
    }
    printf("\nThe contents of SLL are:\n");
    cur=start;
    while(cur!=NULL)
    {
        printf("\n ||%d|| ||%s|| ||%s|| ||%s|| ||%d|| ||%ld||\n",num,cur->name,cur->usn,cur->branch,cur->sem,cur->phone);
        num++;
        cur=cur->link;
    }
}

void stackdemo()
{
    int ch;
    while(1)
    {
        printf("\n~~stack demo using SLL\n");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("\nPlease enter the choice\n");
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
    while(1){
    printf("\n~~~MENU~~~\n");
    printf("\n1.Create a SLL of student nodes:\n2.Display Status\n3.Insert End\n4.Delete End\n5.Stack demo using SLL\n6.Exit");
    printf("\nEnter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
           printf("\nEnter the no. of students\n");
           scanf("%d",&n);
           for(i=1;i<=n;i++)
           {
              start=insertfront();
           }
           break;

        case 2:
           display();
           break;

        case 3:
           start=insertend();
           break;

        case 4:
           start=deleteend();
           break;

        case 5:
           stackdemo();
           break;

        case 6:
           exit(0);
    }
}

}