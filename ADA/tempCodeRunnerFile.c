#include<stdio.h>
#include<stdlib.h>
#define INF 999;
#include<time.h>

int main()
{
    int i,j,k,n,source;
    int w[50][50];
    int visited[50];
    int minwt,totalcost=0,sv=0,ev=0;

    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the weight of the matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",w[i][j]);
        }
    }

    for(i=1;i<=n;i++)
        visited[i]=0;

    visited[source]=1;

    printf("The minimum weight edges in a spanning tree is:\n");
    for(i=1;i<n;i++){
        minwt=INF;
        for(j=1;j<=n;j++){
            if(visited[j]==1){
                for(k=1;k<=n;k++){
                    if(visited[k]!=1 && w[j][k]!=0 && w[j][k]<minwt){
                        sv=j;
                        ev=k;
                        minwt=w[j][k];
                    }
                }
            }
        }

        totalcost+=minwt;
        visited[ev]=1;
        printf("%d-->%d  cost:%d\n",sv,ev,minwt);
    }
    printf("The total cost of minimum spanning tree are:%d\n",totalcost);
}
