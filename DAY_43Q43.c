/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

struct TreeNode* constructTree(int* arr, int n) {
    if (n == 0) {
        return NULL;
    }
    
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    
    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    
    for (int i = 1; i < n; i++) {
        struct TreeNode* current = queue[front++];
        
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        
        if (++i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
    }
    
    free(queue);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = constructTree(arr, n);
    
    inorderTraversal(root);
    printf("\n");
    
    free(arr);
    return 0;
}

