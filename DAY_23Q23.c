/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;
    while (head1 != NULL && head2 != NULL) {
        struct Node* temp;
        if (head1->data < head2->data) {
            temp = createNode(head1->data);
            head1 = head1->next;
        } else {
            temp = createNode(head2->data);
            head2 = head2->next;
        }
        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = temp;
        }
    }
    while (head1 != NULL) {
        struct Node* temp = createNode(head1->data);
        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = temp;
        }
        head1 = head1->next;
    }
    while (head2 != NULL) {
        struct Node* temp = createNode(head2->data);
        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = temp;
        }
        head2 = head2->next;
    }
    return mergedHead;
}