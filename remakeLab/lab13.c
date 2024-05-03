#include "lab13.h"


/* 
for this lab we will be implemnting a heap structure
heaps are a data structre that is a binary tree, in which the parent is always greater than the children
there isnt mcuh different between a heap and a binary tree, besides the rule that the parent is always greater than the children
and its complete, meaning form left to right 
max heap just means the parent is greater than the children
*/


struct Heap_t {

    void* dataNode;
    Heap* left;
    Heap* equal; 
    Heap* right; 

};

Heap *makeHeap(void) {
    // create a heap 
    // we can interpt creating a heap as just creating a node in a binary tree
    // so we can just malloc a new node, and treat it as a heap
    Heap *newNode = malloc(sizeof(Heap));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->equal = NULL;
    newNode->dataNode = NULL;

    return newNode;

}

int compareHeap(void *a, void *b) {
    // this function MUST be removed when submitted
    // but we can assume it comapres a and b
    // if a > b, it retunrs 1, if a < b, it returns -1, if a == b, it returns 0
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}


int insertHeap(Heap *heap , void *data) {
    // "You are required to use randomization to maintain balance during insertion"
    // this is a max heap, so the parent must be greater than the children, randomization is used to maintain balance ???

    //returns 1 on success, 0 on failure

    // first check if the entire thing is empty, if so than this is the start
    if (heap == NULL){
        heap->dataNode = data;
    }

    // or if the start has the same data
    if (heap->dataNode == data){
        heap->equal == data;
    }

    // create a node using the data
    Heap *newNode = malloc(sizeof(Heap));
    if (newNode == NULL) {
        return 0;
    }

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->equal =NULL;
    newNode->dataNode = data;


    // now we can actually insert using binary saerch implementations
    if (compareHeap(heap->dataNode, newNode->dataNode) == 1) {  // if a > b, the present node is "bigger" than the one we are trying to implement. we will go to the left
        heap->left 
    }

}


int main(){

    Heap *myHeap = makeHeap();

    free(myHeap);

}