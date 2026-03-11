/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
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
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[20];
        scanf("%s", operation);
        if (strcmp(operation, "push_front") == 0) {
            int value;
            scanf("%d", &value);
            push_front(&dq, value);
        } else if (strcmp(operation, "push_back") == 0) {
            int value;
            scanf("%d", &value);
            push_back(&dq, value);
        } else if (strcmp(operation, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(operation, "pop_back") == 0) {
            pop_back(&dq);
        }
    }
    return 0;
}
