/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>
void DFS(int vertex, int** graph, int* visited, int* stack, int* topIndex, int n) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, graph, visited, stack, topIndex, n);
        }
    }
    stack[(*topIndex)++] = vertex;
}
int main() {
    int n;
    scanf("%d", &n);
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int topIndex = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited, stack, &topIndex, n);
        }
    }
    for (int i = topIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);
    free(stack);
    return 0;
}
