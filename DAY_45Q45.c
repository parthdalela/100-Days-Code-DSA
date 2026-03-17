/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include <stdio.h>
#include <stdlib.h>
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
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
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
        } else {
            if (front < rear) {
                front++;
            }
        }
    }

    printf("%d\n", height(root));
    return 0;
}