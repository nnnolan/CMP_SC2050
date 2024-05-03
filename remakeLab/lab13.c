#include "lab13.h"


/* 
for this lab we will be implemnting a heap structure
heaps are a data structre that is a binary tree, in which the parent is always greater than the children
there isnt mcuh different between a heap and a binary tree, besides the rule that the parent is always greater than the children
and its complete, meaning form left to right 
*/


struct Heap_t {

    void* data; 
    struct BinaryNode_t* left;
    struct BinaryNode_t* right;

};

typedef struct BinaryNode_t {

    BinaryNode* root;

} BinaryNode;

