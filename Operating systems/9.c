#include<stdio.h>
#include<stdlib.h>
int main()
{
    int block[100],start,length,i,j,again,next;
    for(i=0;i<100;i++)
       block[i]=0;
    do
    {
      printf("LINKED FILE ALLOCATION SIMULATION\n");
      printf("Enter the starting block of the file:\n");
      scanf("%d",&start);
      printf("Enter the number of blocks:\n");
      scanf("%d",&length);
      if(block[start]==1)
      {
        printf("starting block is already allocated,try another\n");
      }
      block[start]=1;
      next=start;
      printf("Allocated blocks\n");
      printf("%d",start);
      for(i=1;i<length;i++)
      {
        for(j=0;j<100;j++)
        {
            if(block[j]==0)
            {
                block[j]=1;
                printf("->%d",j);
                next=j;
                break;
            }
        }
        if(j==100)
        {
            printf("disk is full:\n");
        }
      }
      printf("->-1(end of file)\n");
      printf("Do you want to allcoated any further:(1=yes,0=no)\n");
      scanf("%d",&again);
    }while(again==1);
    printf("Simulation complete\n");
}