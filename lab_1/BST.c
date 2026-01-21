#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    
    if (key < root->key)
        return search(root->left, key);
    
    return search(root->right, key);
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    
    return root;
}

struct Node* searchAndInsert(struct Node* root, int key) {
    struct Node* result = search(root, key);
    
    if (result != NULL) {
        printf("Key %d found.\n", key);
        return root;
    } else {
        printf("Key %d not found.\n", key);
        root = insert(root, key);
        printf("Key %d inserted.\n", key);
        return root;
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void display(struct Node* root) {
    if (root == NULL) {
        printf("tree is empty!\n");
        return;
    }
    
    printf("\n");
    printf("Inorder Traversal:   ");
    inorder(root);
    printf("\n");
    
    printf("Preorder Traversal:  ");
    preorder(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search and Insert a key\n");
        printf("2. Display all traversals\n");
        printf("3. Exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter key to search/insert: ");
                scanf("%d", &key);
                root = searchAndInsert(root, key);
                break;
            
            case 2:
                display(root);
                break;
            
            case 3:
                exit(0);
            
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
