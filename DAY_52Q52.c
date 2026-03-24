/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);
    if (leftLCA && rightLCA) {
        return root;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main() {
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, N);
    free(arr);
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("%d\n", lca->data);
    } else {
        printf("LCA does not exist\n");
    }
    return 0;
}
