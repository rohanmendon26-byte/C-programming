#include<stdio.h>
#include<stdlib.h>

int key[20],n,m;
int count=0;
int *ht,index;

void insert(int key)
{
    index=key%m;
    while(ht[index]!=-1)
    {
        index=(index+1)%m;
    }
    ht[index]=key;
    count++;
}


void display()
{
    int i;
    if(count==0)
    {
        printf("\nHash table is empty");
        return;
    }
    printf("\nHash table contents are:");
    for(i=0;i<m;i++)
       printf("\nT[%d]-->%d",i,ht[i]);
    printf("\n");
    printf("\nTotal records inserted are %d",count);
}

void main()
{
    int i;
    printf("\nEnter the number of records to be inserted:");
    scanf("%d",&n);
    printf("\nEnter two digit memory location for hash table:");
    scanf("%d",&m);
    ht=(int *)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
       ht[i]=-1;
    printf("\nEnter the four digit key values to be inserted:");
    for(i=0;i<n;i++)
       scanf("%d",&key[i]);
    for(i=0;i<n;i++)
    {
        if(count==m)
        {
            printf("\nHash table is full,cannot insert the key value %d",i+1);
            break;
        }
        insert(key[i]);
    }
    display();        
}