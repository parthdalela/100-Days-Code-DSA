/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
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
struct Node* buildTree(int* arr, int n) {
    if (n == 0) {
        return NULL;
    }
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    for (int i = 1; i < n; i++) {
        struct Node* current = queue[front++];
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        if (++i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}
void zigzagTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node** currentLevel = (struct Node**)malloc(100 * sizeof(struct Node*));
    struct Node** nextLevel = (struct Node**)malloc(100 * sizeof(struct Node*));
    int currentCount = 0, nextCount = 0;
    int leftToRight = 1;
    currentLevel[currentCount++] = root;
    while (currentCount > 0) {
        struct Node* node = currentLevel[--currentCount];
        printf("%d ", node->data);
        if (leftToRight) {
            if (node->left) {
                nextLevel[nextCount++] = node->left;
            }
            if (node->right) {
                nextLevel[nextCount++] = node->right;
            }
        } else {
            if (node->right) {
                nextLevel[nextCount++] = node->right;
            }
            if (node->left) {
                nextLevel[nextCount++] = node->left;
            }
        }
        if (currentCount == 0) {
            leftToRight = !leftToRight;
            struct Node** temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
            nextCount = 0;
        }
    }
    free(currentLevel);
    free(nextLevel);
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    free(arr);
    zigzagTraversal(root);
    return 0;
}
