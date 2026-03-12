/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};
void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}
void push_front(struct Deque* dq, int value) {
    if (dq->size == MAX) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}
void push_back(struct Deque* dq, int value) {
    if (dq->size == MAX) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}
void pop_front(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
}
void pop_back(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
}
int main() {
    struct Deque dq;
    initDeque(&dq);
    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    pop_front(&dq);
    pop_back(&dq);
    pop_front(&dq);
    pop_back(&dq);
    return 0;
}
