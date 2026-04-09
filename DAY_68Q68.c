//*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>
void topologicalSort(int** graph, int n) {
    int* inDegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int j = 0; j < n; j++) {
            if (graph[current][j] == 1) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }
    free(inDegree);
    free(queue);
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
    topologicalSort(graph, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}