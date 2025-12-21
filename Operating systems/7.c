#include<stdio.h>
#include<stdlib.h>
int fr[3];

void display()
{
    int i;
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("%d\t",fr[i]);
    }
}

int main()
{
    int flag1,flag2,i,j,pf=0,top=0,frsize=3;
    int page[12]={2,3,2,1,5,2,4,5,3,2,5,2};

    for(i=0;i<frsize;i++)
        fr[i]=-1;

    for(j=0;j<12;j++)
    {
        flag1=0;
        flag2=0;

        for(i=0;i<frsize;i++)
        {
            if(fr[i]==page[j])
            {
                flag1=1;
                flag2=1;
                break;
            }
        }

        if(flag1==0)
        {
            for(i=0;i<frsize;i++)
            {
                if(fr[i]==-1)
                {
                    fr[i]=page[j];
                    flag2=1;
                    pf++;
                    break;
                }
            }
        }

        if(flag2==0)
        {
            fr[top]=page[j];
            top=(top+1)%frsize;
            pf++;
        }
        display();
    }
    printf("\n Number of pages fault=%d\n",pf);
}