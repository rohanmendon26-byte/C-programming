#include<stdio.h>
int i,j;
int isSafe(int processes,int resources,int allocated[][resources],int max[][resources],int available[])
{
    int need[processes][resources];
    int finish[processes];

    for(i=0;i<processes;i++)
    {
        finish[i]=0;
        for(j=0;j<resources;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }

    int work[resources];
    for(i=0;i<resources;i++)
    {
        work[i]=available[i];
    }

    while(1)
    {
        int found=0;
        for(i=0;i<processes;i++)
        {
            if(!finish[i])
            {
                int canAllocate=1;
                for(j=0;j<resources;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        canAllocate=0;
                        break;
                    }
                }

                if(canAllocate)
                {
                    for(j=0;j<resources;j++)
                    {
                        work[j]+=allocated[i][j];
                    }
                    found=1;
                    finish[i]=1;
                    break;
                }
            }
        }
        if(!found)
        {
            break;
        }
    }

    if(!finish[i])
    {
        for(i=0;i<processes;i++)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int processes,resources;
    printf("\nEnter the number of processes:\n");
    scanf("%d",&processes);
    printf("\nEnter the number of resources:\n");
    scanf("%d",&resources);
    int allocated[processes][resources];
    int max[processes][resources];
    int available[resources];

    printf("\nEnter the allocated resource matrix:\n");
    for(i=0;i<processes;i++)
    {
        for(j=0;j<resources;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }

    printf("\nEnter the max resource matrix:\n");
    for(i=0;i<processes;i++)
    {
        for(j=0;j<resources;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nEnter the available resource matrix:\n");
    for(i=0;i<resources;i++)
    {
        scanf("%d",&allocated[i]);
    }

    if(isSafe(processes,resources,allocated,max,available))
    {
        printf("\nThe system is in a safe state\n");
    }
    else
    {

        printf("\nThe system is not in a safe state\n");
    }
}