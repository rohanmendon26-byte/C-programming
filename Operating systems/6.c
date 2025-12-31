#include<stdio.h>
#include<stdlib.h>
#define MAX 25
int main()
{
    int frag[MAX],f[MAX],b[MAX];
    int bf[MAX]={0},ff[MAX];
    int i,j,nb,nf;
    int highest,temp;

    printf("Enter the number of blocks:\n");
    scanf("%d",&nb);

    printf("Enter the number of files:\n");
    scanf("%d",&nf);

    printf("Enter the block for each :\n");
    for(i=0;i<nb;i++)
    {
        printf("Block %d:\n",i+1);
        scanf("%d",&b[i]); 
    }

    printf("Enter the File for each:\n");
    for(i=0;i<nf;i++)
    {
        printf("file %d:\n",i+1);
        scanf("%d",&f[i]); 
    }

    for(i=0;i<nf;i++)
    {
        highest=-1;
        ff[i]=-1;

        for(j=0;j<nb;j++)
        {
            if(bf[j]==0)
            {
                temp=b[j]-f[i];
                if(temp>=0&&temp>highest)
                {
                    highest=temp;
                    ff[i]=j;
                }
            }
        }
        if(ff[i]!=-1)
        {
            frag[i]=highest;
            bf[ff[i]]=1;
        }
        else{
            frag[i]=-1;
        }
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragments");
    for(i=0;i<nf;i++)
    {
        if(ff[i]!=-1)
        {
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",i+1,f[i],ff[i]+1,b[ff[i]],frag[i]);
        }
        else
        {
            printf("\n%d\t%d\t not allocated",i+1,f[i]);
        }
    }
}