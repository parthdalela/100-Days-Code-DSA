/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
void DFS(int vertex, int** graph, int* visited, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, graph, visited, n);
        }
    }
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
    int s;
    scanf("%d", &s);
    int* visited = (int*)calloc(n, sizeof(int));
    DFS(s, graph, visited, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);
    return 0;
}
