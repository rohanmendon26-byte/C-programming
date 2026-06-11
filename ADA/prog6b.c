#include<stdio.h>
#define MAX 20

void warshall(int n,int r[MAX][MAX]){
    int i,j,k;

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
            }
        }
    }

    printf("transitive closure matrix is:\n");

    for(i=1;i<=n;i++){
        printf("\t%d",i);
    }
    printf("\n");

    for(i=1;i<=n;i++){
        printf("%d\t",i);
        for(j=1;j<=n;j++){
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j,n,r[MAX][MAX];

    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the weight matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&r[i][j]);
        }
    }
    warshall(n,r);
    
}