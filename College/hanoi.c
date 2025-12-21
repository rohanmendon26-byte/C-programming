#include<stdio.h>

void tower(int n,char beg,char aux,char end)
{
    if(n==0)
    {
        printf("ilegal,please try non zero values");
    }

    else if(n==1)
    {
        printf("Move disk from %c to %c\n",beg,end);
    }

    else
    {
        tower(n-1,beg,end,aux);
        tower(1,beg,aux,end);
        tower(n-1,aux,beg,end);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    printf("The tower of hanoi for %d has following steps:\n",n);
    tower(n,'a','b','c');
}