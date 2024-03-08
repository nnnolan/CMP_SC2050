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


int main() {

    return 0;
}

