#include <stdio.h>
#include <stdlib.h>

// this code doesn't really run properly but I don't care anymore

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

struct Node* buildTree(){
    int val;
    printf("enter data: ");
    scanf("%d",&val);
    if(val==-1) return NULL;
    struct Node* root = createNode(val);
    printf("left child of %d ->",val);
    root->left=buildTree();
    printf("right child of %d ->",val);
    root->right=buildTree();
    return root;
}

int countNodes(struct Node* root){
    if(root=NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    struct Node *root = buildTree();
    printf("total number of nodes: %d\n",countNodes(root));
    return 0;
}
