#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p[20],bt[20],tat[20],wt[20],i,n;
    float tatavg=0,wtavg=0;

    printf("Enter the number of process:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the burst time process %d\n",i);
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

    printf("PROCESS\tBURST_TIME\tWAITING_TIME\tTURNARROUNDTIME\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\n",i,bt[i],wt[i],tat[i]);
    }

    printf("Average waiting time=%f\n",wtavg/n);
    printf("Average turnarround time=%f\n",tatavg/n);


}