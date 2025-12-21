#include<stdio.h>
int main()
{
    int p[20],bt[20],wt[20],tat[20],i,n;
    float wtavg=0,tatavg=0;

    printf("Enter the number of process:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the burst time for the process %d:",i);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }

    for(i=0;i<n;i++)
    {
        wtavg+=wt[i];
        tatavg+=tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tTURN ARROUND TIME\tWAITING TIME");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t%d\t%d\t%d",i,bt[i],tat[i],wt[i]);
    }
    printf("Average waiting time=%.2f",wtavg/n);
    printf("Average turn arround time=%.2f",tatavg/n);
}