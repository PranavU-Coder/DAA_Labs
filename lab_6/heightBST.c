#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

unsigned int opcount = 0;

struct Node {
    int val;
    struct Node *left, *right;
};
typedef struct Node* NODE;

NODE root = NULL;

NODE insert(int ele, NODE node) {
    if (node == NULL) {
        NODE temp = (NODE)malloc(sizeof(struct Node));
        temp->val = ele;
        temp->left = temp->right = NULL;
        return temp;
    } else if (ele < node->val) {
        node->left = insert(ele, node->left);
    } else if (ele > node->val) {
        node->right = insert(ele, node->right);
    } else {
        printf("Duplicate element found, insertion failed\n");
    }
    return node;
}

int height(NODE node) {
    opcount++;
    if (node == NULL) return -1;
    else return MAX(height(node->left), height(node->right)) + 1;
}

int main() {
    int choice, ele;
    do {
        printf("\n1. Insert an element\n");
        printf("2. Find height of BST\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Insertion: please enter an element: ");
                scanf("%d", &ele);
                root = insert(ele, root); 
                break;
            case 2:
                printf("Height of BST: %d\n", height(root));
                printf("Opcount = %u\n", opcount);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 3);
    return 0;
}
