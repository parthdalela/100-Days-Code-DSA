/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
};
void initQueue(struct Queue* queue, int capacity) {
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
}
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}
void display(struct Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct Queue queue;
    initQueue(&queue, n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&queue, value);
    }
    printf("Queue elements: ");
    display(&queue);
    free(queue.arr); // Free allocated memory
    return 0;
}
