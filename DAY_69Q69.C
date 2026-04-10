/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
typedef struct {
    int vertex;
    int weight;
} Edge;
typedef struct {
    Edge* edges;
    int size;
    int capacity;
} MinHeap;
void initMinHeap(MinHeap* heap, int capacity) {
    heap->edges = (Edge*)malloc(capacity * sizeof(Edge));
    heap->size = 0;
    heap->capacity = capacity;
}
void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->edges[left].weight < heap->edges[smallest].weight) {
        smallest = left;
    }
    if (right < heap->size && heap->edges[right].weight < heap->edges[smallest].weight) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->edges[index], &heap->edges[smallest]);
        minHeapify(heap, smallest);
    }
}
void insertMinHeap(MinHeap* heap, int vertex, int weight) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->edges[heap->size].vertex = vertex;
    heap->edges[heap->size].weight = weight;
    int current = heap->size++;
    while (current > 0 && heap->edges[current].weight < heap->edges[(current - 1) / 2].weight) {
        swap(&heap->edges[current], &heap->edges[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

Edge extractMin(MinHeap* heap) {
    Edge minEdge = heap->edges[0];
    heap->edges[0] = heap->edges[--heap->size];
    minHeapify(heap, 0);
    return minEdge;
}
void dijkstra(int** graph, int n, int source) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    MinHeap heap;
    initMinHeap(&heap, n);
    insertMinHeap(&heap, source, 0);
    while (heap.size > 0) {
        Edge minEdge = extractMin(&heap);
        int u = minEdge.vertex;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                insertMinHeap(&heap, v, dist[v]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Distance from source %d to vertex %d: %d\n", source, i, dist[i]);
    }
    free(dist);
    free(heap.edges);
}
int main() {
    int n, source;
    scanf("%d %d", &n, &source);
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    dijkstra(graph, n, source);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}