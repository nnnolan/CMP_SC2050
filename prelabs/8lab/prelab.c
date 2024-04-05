#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct { 
      int object; 
      struct listStruct *next; 
} List;

List * initList(int* number);
List * insertAtHead(List* myList, int* number);
int getAtIndex(int, List*);
int getListLength(List*);
List * freeList(List*);

List * initList(int* number) {
    // this creates a "head" list

    List* wipList = NULL;
    wipList = malloc(sizeof(List));

    if (!(wipList)) {
        *number = 1;
        return NULL;
    }

    wipList->object = 1;
    wipList->next = NULL;

    *number = 0;
    return wipList;

}
List * insertAtHead(List* myList, int* number){

    List *newItem = malloc(sizeof(List));
    if (!newItem){
        *number = 1;
        return NULL;
    }

    *number = 0;
    newItem->object = 1;
    newItem->next = myList;

    return newItem;

}

int getAtIndex(int index, List* myList){

    // find the return the object of node index

    int count = 0;
    List* current = myList;

    while (current != NULL && count < index) {
        current = current->next;
        count++;
    }

    // if the current node is not NULL, we've found the index
    if (current != NULL) {
        return current->object; // Return the object at the index
    } else {
        // if current is NULL, the index was out of bounds
        printf("Index out of bounds.\n");
        return -1; // Return an error value
    }
}

int getListLength(List* myList){

    int count = 0;
    List* current = myList;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;

}

List * freeList(List* myList){

    List* tempRemoval = myList;

    while(myList != NULL){

        tempRemoval = myList;
        myList = myList->next;
        free(tempRemoval);

    }

    return myList; // null

}

// ------ LAB TWO INITS ------ //
List * insertAtPosition(int pos, int key, List* myList, int* errorCode);
int getAtPosition(int pos, List* myList, int* errorCode);
List * removeAtPosition(int pos, List* myList, int* errorCode);
List * removeObject(int obj, List* myList, int* errorCode);

List * insertAtPosition(int pos, int key, List* myList, int* errorCode){

    List *newItem = malloc(sizeof(List));

    if (!newItem){
        printf("malloc fail\n");
        *errorCode = -1;
        return NULL;
    }

    newItem->object = key;
    newItem->next = NULL;

    // we'll let pos 1 or below handle by inserting at head
    if (pos <= 1) {
        newItem->next = myList;
        printf("inserted at head. was that your intetnion? \n");
        *errorCode = 1;
        return newItem;
    }

    // no we put it in the right spot, wihle also checking if where there
    List *prev = NULL;
    List *current = myList;
    int count = 1;
    while (current != NULL && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }
    // position found, insert the new node
    if (current != NULL) {
        prev->next = newItem;
        newItem->next = current;
        *errorCode = 0;
    }
    // position not found, insert at the end
    else {
        printf("position exceeded list length. inserted at the end. was that oyur intetion?");
        prev->next = newItem;
        *errorCode = 2;
    }

    return myList;
 
}

int getAtPosition(int pos, List* myList, int* errorCode){

    List *prev = NULL;
    if (prev == NULL) {
        printf("yay");
    }
    List *current = myList;
    int count = 1;

    while (current != NULL && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }
    
    if (pos <= 1){
        printf("index less than or equal to one, reutnring object of first index");
        *errorCode = 1;
        return myList->object;
    }

    if (current != NULL) {
        *errorCode =0;
        return current->object;
    } 

    else {

        printf("failed to find position\n");
        *errorCode = -1;
        return -1;

    }

    
}

List * removeAtPosition(int pos, List* myList, int* errorCode){

    if (pos <= 1) {
        printf("pos <=1, first node's object changed to 0. was that ur intention?\n");
        myList->object=0;
        *errorCode = 1;
    }

    List* current = myList;
    int count = 1;

    while (current != NULL && count < pos) {
        current = current->next;
        count++;
    }

    //case 1: Position found, change the int in the node to zero
    if (current != NULL) {
        current->object = 0;
        *errorCode = 1;
    }
    // Case 2: Position not found
    else {
        printf("Position not found\n");
        *errorCode = -1;
    }

    return myList;
}

List * removeObject(int obj, List* myList, int* errorCode){


    List* current = myList;

    while (current != NULL){
        if (current->object == obj) {
            current->object = 0;
        }
    current = current->next;

    }

    *errorCode = 0;
    return myList;
}






int main() {

    return 0;
}

