#include<stdio.h>
#include<stdlib.h>
int main()
{
  int block[100],start,length,i,j,again,next;
  for(i=0;i<100;i++)
  {
    block[i]=0;
  }
  do
  {
    printf("\n\tLINKED FILE SIMULATION:\n");
    printf("\nEnter the starting block of the file:\n");
    scanf("%d",&start);
    printf("\nEnter the number of blocks:\n");
    scanf("%d",&length);
    if(block[start]==1)
    {
      printf("\nStarting block is already occupied try another:\n");
    }
    block[start]=1;
    next=start;
    printf("\nAllocating blocks:\n");
    printf("%d",start);

    for(i=1;i<length;i++)
    {
      for(j=0;j<100;j++)
      {
        if(block[j]==0)
        {
          block[j]=1;
          printf("-->%d",j);
          next=j;
          break;
        }
      }
      if(j==100)
      {
        printf("\ndisk is full");
      }
    }
    printf("-->-1(end of file)");
    printf("\nDo you want to allocate any further(0=left,1=right)?\n");
    scanf("%d",&again);
  }while(again==1);
  printf("\n Simulation complete\n");
}