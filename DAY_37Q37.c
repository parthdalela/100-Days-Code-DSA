/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct PriorityQueue {
    int arr[MAX];
    int size;
};
void initPriorityQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq->arr[pq->size++] = value;
}
void delete(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }
    printf("%d\n", pq->arr[minIndex]);
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}
void peek(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }
    printf("%d\n", pq->arr[minIndex]);
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    struct PriorityQueue pq;
    initPriorityQueue(&pq);
    for (int i = 0; i < n; i++) {
        char operation[10];
        int value;
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(&pq, value);
        } else if (strcmp(operation, "delete") == 0) {
            delete(&pq);
        } else if (strcmp(operation, "peek") == 0) {
            peek(&pq);
        }
    }
    return 0;
}
