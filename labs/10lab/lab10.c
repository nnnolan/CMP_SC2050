#include "lab10.h"


// we are going to implement a queue structure using a fifo idea
// we can interpert a queue a specific type of linked list,s o lets start by making the "node" of this list
struct Queue_t{

    void* data;
    Queue *next;

    // size count
    int size;

    // and i guess the end for o(1)
    Queue *end;

};

// new queue will init a new queue
Queue * newQueue(void){
    
    // create a node to start
    Queue *aNewBeginning = (Queue*)malloc(sizeof(Queue));

    // check for malloc
    if (aNewBeginning == NULL){
        // i mean i guess its null 
        // just more explicit
        return NULL;
    }

    aNewBeginning->data = NULL;
    aNewBeginning->next = NULL;

    // eek
    aNewBeginning->size = 0;

    // more addition
    aNewBeginning->end = NULL;

    return aNewBeginning;

}

// get size counts the items in the queue and reutrns that number
// well since this *has* to be o(1), we gotta store the count in the struct
int getSize(Queue *q){

    return  q->size;

}

int enQueue(Queue *q, void *data){

    // since we give priority to the oldest item, the newest items will be placed to the back
    // kinda like a fridge at a grocerys tore
    // so enqueue throws item to the back
    // also o(1)... hmmm

    Queue *newItem = (Queue*)malloc(sizeof(Queue));

    // check for fail
    if (newItem == NULL){
        //malloc fail
        return 0;
    }

        // now we have to palce it at the end of the list with o(1). hmm. probably have to track a pointer to the end yeah? 
    // will come back


    newItem->data = data;
    newItem->next = NULL;
    newItem->size =0;

    
    if (q->end == NULL) {
        // this means its both start and finish at the same time
        // my implementation is most sense for it to be this way. i think.
        q->next = newItem;
        q->end = newItem;
    }
    else { 
        // first we'll have to make the next pointer of the current end point to the new item
        q->end->next = newItem;
        // and the nthe actual queue's end point to the new item
        q->end = newItem;
    }

    q->size = q->size +1;

    // wow
    return 1;

}


// simply just return the data content of first item, unless its empty
void * peek(Queue *q){

    // if its empty
    if (q == NULL){
        return NULL;
    }

    return q->data;
}

// same idea as peek, except we actually remove first item in order
void * deQueue(Queue *q){   

    // empty check
    if (q == NULL){
        return NULL;
    }

    // store data and an extra pointer to q currently to free
    Queue* temp = q;
    void* dataToReturn = q->data;

    // shift q down one
    q = q->next;

    // take one off the size
    q->size = (q->size) - 1;

    // the first node of the original linked list we were given has now been removed, and the size has been decreased by one, and we have the data to return


    free(temp);
    return dataToReturn;
}

void destroy(Queue *q) {
    /*
    Info: This function takes a Queue, and frees all memory allocated to it. Remember that the data on
the queue belongs to the user, not to your implementation.
    */

    // iterate through the queue and take off the nodes
    // the note implies to leave the *data pointers alone ? im not sure 

    Queue *current = q;
    Queue *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}

// ^_^