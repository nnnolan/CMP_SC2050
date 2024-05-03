#include <stdio.h>
#include <stdlib.h>


typedef struct binaryNode_t{
    int data;
    struct binaryNode_t* left;
    struct binaryNode_t* right;
} binaryNode;

// the tree, this serves as the root of the tree, a dummy node. 
typedef struct binaryTree_t {
    binaryNode* root;
} binaryTree;

// int compareData(void* data1, void* data2) {
//     return (int)data1 - (int)data2;
// }

// create a new binary node
binaryNode* createNode(int data) {
    binaryNode* node = (binaryNode*)malloc(sizeof(binaryNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

binaryNode* insertBST(binaryNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (root->data > data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

binaryNode* findBST(binaryNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (root->data > data) {
        return findBST(root->left, data);
    } else {
        return findBST(root->right, data);
    }
}

void freeBST(binaryNode* root) {
    if (root == NULL) {
        return;
    }
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

void printBST(binaryNode* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    printf("%d ", root->data);
    printBST(root->right);
}

int main() {
    printf("Hello World!\n");


    binaryNode* root = NULL;

    // int *p1 = (int*)malloc(sizeof(int));
    // *p1 = 5;

    // int *p2 = (int*)malloc(sizeof(int));
    // *p2 = 3;

    // int *p3 = (int*)malloc(sizeof(int));
    // *p3 = 7;

    // int *p4 = (int*)malloc(sizeof(int));
    // *p4 = 2;

    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 6);
    root = insertBST(root, 8);
    root = insertBST(root, 1);


    printBST(root);
    free(root);

}