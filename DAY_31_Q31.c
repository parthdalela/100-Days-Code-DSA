/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}
void pop() {
    if (top >= 0) {
        printf("%d\n", stack[top--]);
    } else {
        printf("Stack Underflow\n");
    }
}
void display() {
    if (top >= 0) {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}
int main() {
    int n, operation, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);
        if (operation == 1) {
            scanf("%d", &value);
            push(value);
        } else if (operation == 2) {
            pop();
        } else if (operation == 3) {
            display();
        }
    }
    return 0;
}
