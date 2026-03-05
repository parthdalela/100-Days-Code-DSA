/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token; // Append operand to postfix
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '('
            }
            pop(); // Pop '('
        } else { // Operator
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(token); // Push current operator
        }
    }
    while (top >= 0) {
        postfix[j++] = pop(); // Pop remaining operators
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}