#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[25],name[25],dept[25],desig[25];
    int sal;
    long int phone;
    struct node *rlink;
    struct node *llink;
};


typedef struct node *NODE;
NODE first=NULL;
int count=0;

NODE create()
{
    NODE enode;
    enode=(struct node *)malloc(sizeof(struct node));
    if(enode==NULL)
    {
        printf("\nMemory is not available");
        exit(0);
    }
    printf("\nEnter the ssn,name,dept,desig,sal and phone:");
    scanf("%s %s %s %s %d %ld",enode->ssn,enode->name,enode->dept,enode->desig,&enode->sal,&enode->phone);
    enode->rlink=NULL;
    enode->llink=NULL;
    count++;
    return enode;
}

NODE insertfront()
{
    NODE temp;
    temp=create();

    if(first==NULL)
    {
        return temp;
    }

    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE deletefront()
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("\nThe student node with ssn %s is deleted",first->ssn);
        free(first);
        count--;
        return NULL;
    }

    temp=first;
    first=first->rlink;
    temp->rlink=NULL;
    first->llink=NULL;
    printf("\nThe student with ssn %s is deleted",temp->ssn);
    free(temp);
    count--;
    return first;
}


NODE insertend()
{
    NODE temp,cur;
    temp=create();
    
    if(first==NULL)
    {
        return temp;
    }

    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}

NODE deleteend()
{
    NODE prev,cur;
     if(first==NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("\nThe student node with ssn %s is deleted",first->ssn);
        free(first);
        count--;
        return NULL;
    }

    prev=NULL;
    cur=first;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur=cur->rlink;
    }
    cur->llink=NULL;
    printf("\nThe student nodes with ssn %s is deleted",cur->ssn);
    prev->rlink=NULL;
    free(cur);
    count--;
    return first;
}

void display()
{
    NODE cur;
    int num=1;
     
    if(first==NULL)
    {
        printf("\nNo items to display");
        return;
    }

    printf("\ncontents in DLL are:");
    cur=first;
    while(cur!=NULL)
    {
        printf("\n||%d||ssn:%s|name:%s|dept:%s|desig:%s|sal:%d|phone:%ld|",num,cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phone);
        num++;
        cur=cur->rlink;
    }
    printf("\nThe total nodes:%d",count);
}

void deqdemo()
{
    int ch;
    while(1)
    {
        printf("\n~~Double ended queue operation~~");
        printf("\n1.insertQueueFront\n2.DeleteQueueFront\n3.InsertQueueEnd\n4.DeleteQueueEnd\n5.display\n6.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               first=insertfront();
               break;

            case 2:
               first=deletefront();
               break;

            case 3:
               first=insertend();
               break;

            case 4:
               first=deleteend();
               break;

            case 5:
               display();
               break;

            case 6:
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
        printf("\n~~MENU~~");
        printf("\n1.Create a dll of student nodes\n2.insertQueueFront\n3.DeleteQueueFront\n4.InsertQueueEnd\n5.DeleteQueueEnd\n6.display\n7.deq operation\n8.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the number of students:");
               scanf("%d",&n);
               for(i=1;i<=n;i++)
               {
                  first=insertend();
               }
               break;

            case 2:
               first=insertfront();
               break;

            case 3:
               first=deletefront();
               break;

            case 4:
               first=insertend();
               break;

            case 5:
               first=deleteend();
               break;

            case 6:
               display();
               break;

            case 7:
               deqdemo();
               break;

            case 8:
               exit(0);
        }
    }
}