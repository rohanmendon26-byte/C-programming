#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p[20],bt[20],wt[20],tat[20],i,n;
    float wtavg=0,tatavg=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time for process %d\n",i);
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
        tatavg+=tat[i];
        wtavg+=wt[i];
    }

    printf("\nPROCESS\tBURST_TIME\tWAITING_TIME\tTURN_ARROUNDTIME\n");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }

    printf("\nAverage turnarround time:%.2f\n",tatavg/n);
    printf("\nAverage waiting time:%.2f\n",wtavg/n);

}