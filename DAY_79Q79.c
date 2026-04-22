/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
typedef struct {
    int vertex;
    int weight;
} Edge;
typedef struct {
    Edge* edges;
    int count;
} AdjList;
typedef struct {
    AdjList* adjLists;
    int numVertices;
} Graph;
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (AdjList*)malloc(numVertices * sizeof(AdjList));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i].edges = NULL;
        graph->adjLists[i].count = 0;
    }
    return graph;
}
void addEdge(Graph* graph, int u, int v, int w) {
    graph->adjLists[u].edges = (Edge*)realloc(graph->adjLists[u].edges, (graph->adjLists[u].count + 1) * sizeof(Edge));
    graph->adjLists[u].edges[graph->adjLists[u].count - 1].vertex = v;
    graph->adjLists[u].edges[graph->adjLists[u].count - 1].weight = w;
}
void dijkstra(Graph* graph, int source) {
    int* dist = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    for (int count = 0; count < graph->numVertices - 1; count++) {
        int minDist = INF, minIndex;
        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;
        for (int j = 0; j < graph->adjLists[minIndex].count; j++) {
            Edge edge = graph->adjLists[minIndex].edges[j];
            if (!visited[edge.vertex] && dist[minIndex] != INF && dist[minIndex] + edge.weight < dist[edge.vertex]) {
                dist[edge.vertex] = dist[minIndex] + edge.weight;
            }
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
    free(dist);
    free(visited);
}
int main() {
    int n, m, source;
    scanf("%d %d", &n, &m);
    Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w);
        addEdge(graph, v - 1, u - 1, w); // For undirected graph
    }
    scanf("%d", &source);
    dijkstra(graph, source - 1);
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjLists[i].edges);
    }
    free(graph->adjLists);
    free(graph);
    return 0;
}
