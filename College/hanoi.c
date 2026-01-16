#include<stdio.h>
void tower(int n,char beg,char aux,char end)
{
    if(n==0)
    {
        printf("\nillegal,try with non zero numbers");
    }
    else if(n==1)
    {
        printf("\nMove from disk %c to %c",beg,end);
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
    printf("\nEnter the number of disks:");
    scanf("%d",&n);
    printf("\ntower of hanoi for %d has following steps",n);
    tower(n,'a','b','c');
}