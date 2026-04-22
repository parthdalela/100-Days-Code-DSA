/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
typedef struct {
    int u;
    int v;
    int w;
} Edge;
void bellmanFord(Edge* edges, int n, int m, int source) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            free(dist);
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
    free(dist);
}
int main() {
    int n, m, source;
    scanf("%d %d %d", &n, &m, &source);
    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    bellmanFord(edges, n, m, source);
    free(edges);
    return 0;
}
