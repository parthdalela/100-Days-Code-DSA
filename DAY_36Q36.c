/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>
#include <stdlib.h>
struct CircularQueue {
    int* arr;
    int front;
    int rear;
    int capacity;
};
void initCircularQueue(struct CircularQueue* queue, int capacity) {
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
}
void enqueue(struct CircularQueue* queue, int value) {
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
}
void dequeue(struct CircularQueue* queue) {
    if (queue->front == (queue->rear + 1) % queue->capacity) {
        printf("Queue Underflow\n");
        return;
    }
    queue->front = (queue->front + 1) % queue->capacity;
}
void display(struct CircularQueue* queue) {
    int i = queue->front;
    while (i != (queue->rear + 1) % queue->capacity) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}
int main() {
    int n, m;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    struct CircularQueue queue;
    initCircularQueue(&queue, n + 1); // +1 for circular queue
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&queue, value);
    }
    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&queue);
    }
    printf("Queue elements after operations: ");
    display(&queue);
    return 0;
}
