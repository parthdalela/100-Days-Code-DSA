/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

void push(int val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    int* queue = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Push all elements of the queue onto the stack
    for (int i = 0; i < n; i++) {
        push(queue[i]);
    }

    // Pop all elements from the stack and print them
    for (int i = 0; i < n; i++) {
        printf("%d ", pop());
    }
    printf("\n");

    free(queue);
    return 0;
}
