#include <stdio.h>

#define MAX 20

int dist[MAX];
int visited[MAX];
int path[MAX];
int source;

int minDistance(int n);
void printPath(int path[], int j);

void dijkstra(int n, int graph[MAX][MAX])
{
    int i, u, v;

    /* Initially set all nodes as unvisited */
    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    /* Mark source as visited */
    visited[source] = 1;

    /* Initialize distance array */
    for(i = 1; i <= n; i++)
    {
        dist[i] = graph[source][i];
    }

    /* Initialize path array */
    for(i = 1; i <= n; i++)
    {
        path[i] = source;
    }

    /* Source has no parent */
    path[source] = -1;

    for(i = 1; i < n; i++)
    {
        u = minDistance(n);

        if(u == -1)
            break;

        visited[u] = 1;

        for(v = 1; v <= n; v++)
        {
            if(!visited[v] &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
}

int minDistance(int n)
{
    int min = 999;
    int minIndex = -1;
    int i;

    for(i = 1; i <= n; i++)
    {
        if(visited[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printPath(int path[], int j)
{
    if(path[j] == -1)
        return;

    printPath(path, path[j]);
    printf(" ---> %d", j);
}

void printShortest(int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(i != source)
        {
            printf("\nThe shortest distance from node %d to %d = %d",
                   source, i, dist[i]);

            printf("\nThe shortest path from node %d to %d is: ",
                   source, i);

            printf("%d", source);
            printPath(path, i);

            printf("\n");
        }
    }
}

int main()
{
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the weight matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(n, graph);

    printShortest(n);

    return 0;
}