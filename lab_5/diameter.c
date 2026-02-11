#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create() {
    int x;
    printf("enter data: ");
    scanf("%d", &x);
    if (x == -1) return NULL;  

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    printf("enter left child of %d: ", x);
    newNode->left = create();

    printf("enter right child of %d: ", x);
    newNode->right = create();

    return newNode;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node *root) {
    if (root == NULL) return 0;

    int Lheight = height(root->left);
    int Rheight = height(root->right);

    int Ldiameter = diameter(root->left);
    int Rdiameter = diameter(root->right);
    return max(Lheight + Rheight + 1, max(Ldiameter, Rdiameter));
}

int main() {
    struct Node *root = NULL;   
    printf("create a BT:\n");
    root = create();
    printf("diameter: %d\n", diameter(root));
    return 0;
}
