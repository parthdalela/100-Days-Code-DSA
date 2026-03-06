/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Indicate error
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}
int isOperator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    stack.top = NULL;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        if (token >= '0' && token <= '9') {
            push(&stack, token - '0'); // Convert char to int
        } else if (isOperator(token)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;
            switch (token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack); // Final result
}
int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    // Remove newline character if present
    postfix[strcspn(postfix, "\n")] = '\0';
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
