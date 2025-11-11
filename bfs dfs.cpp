#include <stdio.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest)
 {
    graph[src][dest] = 1;
    graph[dest][src] = 1; 
}

void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex)
 {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    visited[startVertex] = 1;
    queue[++rear] = startVertex;
        printf("BFS traversal: ");    
    while (front != rear) 
	{
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        for (int i = 0; i < vertices; i++)
		{
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int vertex, int visited[MAX_VERTICES]) 
{
    visited[vertex] = 1;
    printf("%d ", vertex);
	    for (int i = 0; i < vertices; i++)
	 {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}

int main()
 {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    if (vertices < 0 || vertices > MAX_VERTICES)
	 {
        printf("Invalid number of vertices\n");
        return 1;
    }
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    if (edges < 0 || edges > vertices * (vertices - 1)) 
	{
        printf("Invalid number of edges\n");
        return 1;
    }
    printf("Enter edges (source destination): ");
    for (int i = 0; i < edges; i++) 
	{
        int src, dest;
        scanf("%d %d", &src, &dest);
        
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) 
		{
            printf("Invalid vertex entered\n");
            i--;
            continue;
        }
        
        addEdge(graph, src, dest);
    }
    
    printf("Adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) 
	{
        for (int j = 0; j < vertices; j++) 
		{
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    int startVertex;
    printf("Enter starting vertex for traversal: ");
    scanf("%d", &startVertex);
    
    if (startVertex < 0 || startVertex >= vertices) 
	{
        printf("Invalid starting vertex\n");
        return 1;
    }
    
    BFS(graph, vertices, startVertex);
    
    int visitedDFS[MAX_VERTICES] = {0};
    printf("DFS traversal: ");
    DFS(graph, vertices, startVertex, visitedDFS);
    printf("\n");
    
    return 0;
}

