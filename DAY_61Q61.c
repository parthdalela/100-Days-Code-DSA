/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize adjacency matrix
    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *)calloc(n, sizeof(int));
    }

    // Read edges and populate adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1; // For directed graph
        // For undirected graph, also set adjMatrix[v][u] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
