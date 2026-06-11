#include<stdio.h>
#define MAX_ITEMS 10

int max(int a,int b){
    return a>b?a:b;
}


int knapsack(int W,int wt[],int val[],int n){
    int i,j;
    int v[MAX_ITEMS+1][W+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0){
                v[i][j]=0;
            }

            else if(j-wt[i]<0){
                v[i][j]=v[i-1][j];
            }

            else{
                v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
            }
        }

    }

    return v[n][W];
}

void main(){
    int i;
    int n;
    int W;
    int wt[MAX_ITEMS];
    int val[MAX_ITEMS];

    printf("\n Enter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the weight of the items:");
    for(i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }

    printf("\nEnter the value of items:");
    for(i=0;i<n;i++){
        scanf("%d",&val[i]);
    }

    printf("\n Enter the Knapsack capacity:");
    scanf("%d",&W);

    printf("The maximum value of knapsack capacity of capacity %d is %d",W,knapsack(W,wt,val,n));
}