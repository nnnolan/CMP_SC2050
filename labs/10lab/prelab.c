#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node;
struct Node_t {

    void* data;
    Node *next;

};


Node* initEmptyList(int* errorCode);
int insertHead(void *item, Node **list);
void* getHeadObject(Node *list);
int removeHead(Node **list);
int insertTail(void *item, Node **list);
void* getTailObject(Node *list);
int getLength(Node *list);
int deleteList(Node **list);

int main() {
    return 0;
}


Node* initEmptyList(int* errorCode){
    /* This function returns an empty list. Parameter is a reference to an error code. */

    Node* startOfList = (Node*)malloc(sizeof(Node));

    if (startOfList == NULL){
        *errorCode = 1;
        printf("malloc error");
        return startOfList;
    }
    
    startOfList->data =NULL;
    startOfList->next = NULL;

    *errorCode = 0;

    return startOfList;

}

int insertHead(void *item, Node **list){

    Node* newItem = (Node*)malloc(sizeof(Node));
    if (newItem == NULL){
        return 1;
    }

    newItem->data = item;
    newItem->next = *list;

    *list = newItem;

    return 0;

}

void * getHeadObject(Node *list) {

    return list->data;

}

int removeHead(Node **list){

    // remove the first and update the pointer to the second in order
    if (*list == NULL) {
        return 1;
    }

    Node *temp = *list;

    *list = (*list)->next;
    free(temp);

    return 0;

}

int insertTail(void *item, Node **list){

    Node *newItem = (Node*)malloc(sizeof(Node));

    if (newItem == NULL) {
        return 1;
    }

    newItem->data = item;
    newItem->next = NULL;

    if (*list == NULL){
        *list = newItem;
    }

    else {
        Node *current = *list;

        while (current->next != NULL){
            current = current->next;
        }
        current->next = newItem;

    }

    return 0;

}

void* getTailObject(Node *list){

    Node *current = list;
    while (current->next != NULL){
        current = current->next;
    }

    return current->data;

}

int getLength(Node *list){

    int count = 0;

    Node *current = list;
    while (current->next != NULL) {
        count +=1;
        current = current->next;
    }

    return count;
}



int deleteList(Node **list){

    Node *current = *list;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *list = NULL;
}