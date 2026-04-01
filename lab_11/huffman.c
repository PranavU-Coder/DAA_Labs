#include <stdio.h>
#include <stdlib.h>

struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char symbol, int frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->symbol = symbol;
    temp->frequency = frequency;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void sortNodes(struct Node** nodes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->frequency > nodes[j]->frequency) {
                swap(&nodes[i], &nodes[j]);
            }
        }
    }
}

struct Node* huffmanTree(struct Node** nodes, int numNodes) {
    while (numNodes > 1) {
        sortNodes(nodes, numNodes);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* parent = newNode(' ', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        nodes[1] = nodes[numNodes - 1];
        numNodes--;
    }
    return nodes[0]; 
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes;
    scanf("%d", &numNodes);

    struct Node** nodes = (struct Node**)malloc(sizeof(struct Node*) * numNodes);

    for (int i = 0; i < numNodes; i++) {
        char symbol;
        int frequency;
        scanf(" %c %d", &symbol, &frequency);
        nodes[i] = newNode(symbol, frequency);
    }

    struct Node* root = huffmanTree(nodes, numNodes);

    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}
