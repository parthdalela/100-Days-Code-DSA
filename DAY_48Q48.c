/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    struct Node* root = NULL;
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (val != -1) {
            struct Node* newNode = createNode(val);
            if (root == NULL) {
                root = newNode;
            } else {
                if (queue[front]->left == NULL) {
                    queue[front]->left = newNode;
                } else {
                    queue[front]->right = newNode;
                    front++;
                }
            }
            queue[rear++] = newNode;
        }
    }
    int leafCount = countLeafNodes(root);
    printf("%d\n", leafCount);
    return 0;
}
