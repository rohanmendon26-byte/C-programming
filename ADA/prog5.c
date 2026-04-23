#include<stdio.h>
#include<stdlib.h>
#define INF 999
int parent[100],cost[50][50];

int findParent(int i){
    if(parent[i]!=0){
        i=parent[i];
    }
    return i;
}

int unionVertices(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int i,j,n,min,ne=1;
    int u=0,v=0,a=0,b=0,mincost=0;

    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        parent[i]=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=INF;
            }
        }
    }

    printf("Edges of the minimum spanning tree:\n");

    while(ne<n)
    {
        min=INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    u=a=i;
                    v=b=j;
                }
            }
        }

        u=findParent(u);
        v=findParent(v);

        if(unionVertices(u,v)){
            printf("%d edge selected (%d...%d) cost:%d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[a][b]=INF;
    }
    printf("Minimum cost = %d\n",mincost);
    return 0;
}