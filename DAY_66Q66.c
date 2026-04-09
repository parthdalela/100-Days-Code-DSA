/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
int DFS(int vertex, int** graph, int* visited, int* recStack, int n) {
    visited[vertex] = 1;
    recStack[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1) {
            if (!visited[i] && DFS(i, graph, visited, recStack, n)) {
                return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }
    recStack[vertex] = 0;
    return 0;
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
    int* recStack = (int*)calloc(n, sizeof(int));
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && DFS(i, graph, visited, recStack, n)) {
            hasCycle = 1;
            break;
        }
    }
    printf(hasCycle ? "YES\n" : "NO\n");
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);
    free(recStack);
    return 0;
}
