#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Structure for adjacency list node */
struct Node
{
    int vertex;
    struct Node *next;
};

/* Graph structure */
struct Graph
{
    int vertices;
    struct Node *adjList[MAX];
};

/* Queue for BFS */
int queue[MAX];
int front = -1, rear = -1;

/* Function to create graph */
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

/* Create new adjacency list node */
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Add edge to graph (Undirected) */
void addEdge(struct Graph *graph, int src, int dest)
{
    if (src < 0 || dest < 0 || src >= graph->vertices || dest >= graph->vertices)
    {
        printf("Invalid vertex!\n");
        return;
    }

    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;

    printf("Edge added successfully.\n");
}

/* Display graph */
void displayGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* Queue operations */
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

/* BFS traversal */
void BFS(struct Graph *graph, int start)
{
    int visited[MAX] = {0};

    if (start < 0 || start >= graph->vertices)
    {
        printf("Invalid starting vertex!\n");
        return;
    }

    printf("BFS Traversal: ");

    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        int current = dequeue();
        printf("%d ", current);

        struct Node *temp = graph->adjList[current];
        while (temp)
        {
            int adj = temp->vertex;
            if (!visited[adj])
            {
                visited[adj] = 1;
                enqueue(adj);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    front = rear = -1;
}

/* DFS traversal */
void DFSUtil(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp)
    {
        int adj = temp->vertex;
        if (!visited[adj])
            DFSUtil(graph, adj, visited);
        temp = temp->next;
    }
}

void DFS(struct Graph *graph, int start)
{
    int visited[MAX] = {0};

    if (start < 0 || start >= graph->vertices)
    {
        printf("Invalid starting vertex!\n");
        return;
    }

    printf("DFS Traversal: ");
    DFSUtil(graph, start, visited);
    printf("\n");
}

/* Main function */
int main()
{
    struct Graph *graph = NULL;
    int choice, vertices, src, dest, start;

    do
    {
        printf("\n----- PATHFINDING USING GRAPHS -----\n");
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. BFS Traversal\n");
        printf("5. DFS Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of vertices (max %d): ", MAX);
            scanf("%d", &vertices);

            if (vertices <= 0 || vertices > MAX)
            {
                printf("Invalid number of vertices!\n");
                break;
            }

            graph = createGraph(vertices);
            printf("Graph created successfully.\n");
            break;

        case 2:
            if (!graph)
            {
                printf("Create graph first!\n");
                break;
            }
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;

        case 3:
            if (!graph)
            {
                printf("Graph not created!\n");
                break;
            }
            displayGraph(graph);
            break;

        case 4:
            if (!graph)
            {
                printf("Graph not created!\n");
                break;
            }
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &start);
            BFS(graph, start);
            break;

        case 5:
            if (!graph)
            {
                printf("Graph not created!\n");
                break;
            }
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &start);
            DFS(graph, start);
            break;

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
