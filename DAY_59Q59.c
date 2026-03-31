/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
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
int search(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
struct Node* buildTree(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    struct Node* node = createNode(postorder[(*postIndex)--]);
    if (inStart == inEnd) {
        return node;
    }
    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return node;
}
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    int* inorder = (int*)malloc(N * sizeof(int));
    int* postorder = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    int postIndex = N - 1;
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);
    preorderTraversal(root);
    free(inorder);
    free(postorder);
    return 0;
}
