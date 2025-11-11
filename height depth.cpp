#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Not enough memory\n");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int CalculateHeight(struct node* root) {
    if (root == NULL)
        return -1;
    int leftHeight = CalculateHeight(root->left);
    int rightHeight = CalculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int calculateDepth(struct node* root, int targetData, int unsentDepth) {
    if (root == NULL)
        return -1;
    if (root->data == targetData)
        return unsentDepth;
    if (targetData < root->data)
        return calculateDepth(root->left, targetData, unsentDepth + 1);
    else
        return calculateDepth(root->right, targetData, unsentDepth + 1);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int treeHeight = CalculateHeight(root);
    printf("Height of BST: %d\n", treeHeight);

    int targetNodeData = 40;
    int nodeDepth = calculateDepth(root, targetNodeData, 0);
    if (nodeDepth != -1)
        printf("Depth of node %d is %d\n", targetNodeData, nodeDepth);
    else
        printf("Node %d not found in BST\n", targetNodeData);

    return 0;
}

