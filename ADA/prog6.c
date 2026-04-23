#include<stdio.h>
#define MAX 20

int min(int a,int b){
    if(a<b)
       return a;
    else
       return b;
}

void floyd(int n,int d[MAX][MAX],int w[MAX][MAX]){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            d[i][j]=w[i][j];
        }
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    printf("All pairs shortest path matrix:\n");

    for(i=1;i<=n;i++){
        printf("\t%d",i);
    }
    printf("\n");

    for(i=1;i<=n;i++){
        printf("%d\t",i);
    for(j=1;j<=n;j++){
        printf("%d\t",d[i][j]);
    }
    printf("\n");
}
}

int main(){
    int i,j,k,n,w[MAX][MAX],d[MAX][MAX];
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the weight matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&w[i][j]);
        }
    }

    floyd(n,d,w);
    return 0;
}