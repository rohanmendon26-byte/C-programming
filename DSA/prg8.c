#include<stdio.h>
#include<stdlib.h>

struct node{
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
        printf("\nRunning out of memory\n");
        exit(0);
    }
    printf("\nEnter the ssn,name,dept,designation,sal and phone\n");
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
    temp->llink=NULL;
    return temp;
}

NODE deletefront()
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nEmpty\n");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("\n The student with ssn %s is deleted \n",first->ssn);
        count--;
        free(first);
        return NULL;
    }
    temp=first;
    first=first->rlink;
    first->llink=NULL;
    printf("\n The student with ssn %s is deleted \n",first->ssn);
    count--;
    free(temp);
    return first;

}

NODE insertend()
{
    NODE temp,cur;
    temp=create();
    if(first==NULL)
    {
        printf("\nEmpty\n");
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
    NODE cur,prev;
    if(first==NULL)
    {
        printf("\nEmpty\n");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("\n The student with ssn %s is deleted \n",first->ssn);
        count--;
        free(first);
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
    printf("\nThe student with ssn %s is deleted\n",cur->ssn);
    prev->rlink=NULL;
    count--;
    return first;
}

void display()
{
    NODE cur;
    int num=1;
    if(first==NULL)
    {
        printf("\nNo contents to display\n");
        return;
    }
    cur=first;
    while(cur!=NULL)
    {
        printf("\n|%d| ||SSN:%s|| ||NAME:%s|| ||DEPT:%s|| ||DESIG:%s|| ||SAL:%d|| ||PHONE:%ld||\n",num,cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phone);
        num++;
        cur=cur->rlink;
    }
    printf("\nThe total number of students are: %d\n",count);
}

NODE deqdemo()
{
    int ch;
    while(1)
    {
        printf("\nDouble ended queue operations\n");
        printf("1.Insert queue front\n2.delete queue front\n3.display status\n4.Exit\n");
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               first=insertend();
               break;

            case 2:
               first=deletefront();
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
    printf("\n~~MENU~~\n");
    printf("\n1.Create DLL of Student nodes\n2.display\n3.Insert at front\n4.delete at front\n5.insert at end\n6.delete at end\n7.Double ended queue operation:\n8.EXIT");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
           printf("\nEnter the number of student nodes:\n");
           scanf("%d",&n);
           for(i=1;i<=n;i++)
           {
              first=insertend();
           }
           break;

        case 2:
           display();
           break;

        case 3:
           first=insertfront();
           break;

        case 4:
           first=deletefront();
           break;

        case 5:
           first=insertend();
           break;

        case 6:
           first=deleteend();
           break;

        case 7:
           deqdemo();
           break;

        case 8:
           exit(0);
    }
}


}