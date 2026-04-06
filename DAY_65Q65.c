/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int hasCycleUtil(Graph* graph, int vertex, int parent, int* visited) {
    visited[vertex] = 1;
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            if (hasCycleUtil(graph, temp->vertex, vertex, visited)) {
                return 1;
            }
        } else if (temp->vertex != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int hasCycle(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, -1, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    if (hasCycle(graph)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    freeGraph(graph);
    return 0;
}

