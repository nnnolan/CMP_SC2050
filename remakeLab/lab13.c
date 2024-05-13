#include "lab13.h"


/* 
for this lab we will be implemnting a heap structure
heaps are a data structre that is a binary tree, in which the parent is always greater than the children
there isnt mcuh different between a heap and a binary tree, besides the rule that the parent is always greater than the children
and its complete, meaning form left to right 
max heap just means the parent is greater than the children
*/


struct Heap_t {
    struct Heap_t* root; // trakcs the root
};

typedef struct HeapNode_t {
    void* nodeData;
    struct HeapNode_t *left;
    struct HeapNode_t *right;
} HeapNode;

// my functs
HeapNode *createNode(void* data);
void swapNodes (HeapNode *a, HeapNode *b);
void destroyNode(HeapNode *node);



// creates a new node, returns null if not well else the node. 
HeapNode *createNode(void* data){
    HeapNode *myNode = malloc(sizeof(HeapNode));
    
    if (myNode == NULL) {
        return NULL;
    }
    
    myNode->nodeData = data;
    myNode->left = NULL;
    myNode->right = NULL;

    return myNode;
}


void destroyNode(HeapNode *node) {
    // lil recusrive stuff
    if (node == NULL) { 
        return;
    }
    destroyNode(node->left);
    destroyNode(node->right);
    free(node);
}



Heap *makeHeap(void) {
    // createa heap in o(1)
    // null if memory else returns teh heeap
    Heap *newHeap = malloc(sizeof(Heap));
    if (newHeap == NULL) {
        return NULL;
    }

    newHeap->root = NULL;

    return newHeap;
}

// int insertHeap(void *a, void *b)
// not needed so wtvs ? :D

int insertHeap(Heap *heap, void *data) {
    // this is the meat and potatoes of this program
    // insert a heap in this heap using  randomization.
    // one on success, zero on faulure

    HeapNode *newNode = createNode(data);
    if (newNode == NULL) {
        return 0;
    }

    int randomDirection = toss(); // we will assume 0 goes left, and right goes 1

    // we don't have a start
    if (heap->root == NULL){
        heap->root = heap;
        return 1;
    } else {

        HeapNode *parent = heap->root;

        // start finding
        while (1) {
            if (randomDirection == 0) { // we are going left
                if (parent->left == NULL) { // we have found the extent
                    parent->left = newNode; // replace it
                    break;
                } 
                // else go down one
                parent = parent->left;

            } else { // now we go right
                if (parent->right == NULL) { // likewise found the extent
                    parent->right = newNode; // replace it
                    break;
                }
                // else keep going on
                parent = parent->right;
            }
        randomDirection = rand() %2; // more random location
        }

    }
    // mama we made it
    return 1;
    
}

void *deleteMax(Heap *heap) {
    // binary ysearch for the max and then delete it
    if (heap->root == NULL){
        return NULL; // empty
    }

    // we can use compare to determine if we go right or left, which is essential log n, dividing everything i nhalf. i think
    HeapNode *parent = heap->root;
    while(1) {
        if (parent->left == NULL && parent->right == NULL){
            // we foudn the max !
            void* tempData = parent->nodeData;
            destroyNode(parent);
            return tempData;

        }
        if (compareHeap(parent->left, parent->right) == 1){ // left is bigger than right, we go that way
            parent = parent->left;
        } else if (compareHeap(parent->left, parent->right) == -1) { // right is bigger than left, we go that way
            parent = parent->right;
        }
        else{
            printf("idk sorry");
            break;
        }
    };

    return NULL;

}

void destroy(Heap *heap) {
    // delete all

    if (heap == NULL){
        return; // empty 
    }

    destroy(heap->root);
    free(heap);
}


int main(){

}