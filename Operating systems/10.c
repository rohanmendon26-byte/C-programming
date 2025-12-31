#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,queue[20],head,maxtrack,direction,temp,i,j,seektime=0;
    printf("\nEnter the number of disks:\n");
    scanf("%d",&n);
    printf("\nEnter the disk request queue\n");
    for(i=0;i<n;i++)
       scanf("%d",&queue[i]);
    printf("\nEnter the initial head position:\n");
    scanf("%d",&head);
    printf("\nEnter the maxtrack number:\n");
    scanf("%d",&maxtrack);
    printf("\nEnter the direction:(0=left,1=right)\n");
    scanf("%d",&direction);

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    int current=head;
    printf("\nSeek Sequence\n");
    printf("%d->",head);

    if(direction==0)
    {
        for(i=n-1;i>=0;i--)
        {
            if(queue[i]<head)
            {
                printf("%d->",queue[i]);
                seektime+=abs(current-queue[i]);
                current=queue[i];  
            }
        }
        printf("0->");
        seektime+=current;
        current=0;

        for(i=0;i<n;i++)
        {
            if(queue[i]>head)
            {
                printf("%d->",queue[i]);
                seektime+=abs(current-queue[i]);
                current=queue[i];
            }
        }
    }

    else
    {
         for(i=0;i<n;i++)
        {
            if(queue[i]>head)
            {
                printf("%d->",queue[i]);
                seektime+=abs(current-queue[i]);
                current=queue[i];
            }
        }
        printf("%d->",maxtrack);
        seektime+=abs(current-maxtrack);
        current=maxtrack;

         for(i=n-1;i>=0;i--)
        {
            if(queue[i]<head)
            {
                printf("%d->",queue[i]);
                seektime+=abs(current-queue[i]);
                current=queue[i];  
            }
        }

    }
    printf("0");
    printf("\nSeek sequence:%d\n",seektime);
}