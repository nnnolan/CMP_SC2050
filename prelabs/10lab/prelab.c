#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_t {
    
    void* data;
    struct Stack_t *next;

}Stack;

Stack* initEmptyStack (int *errorCode);
int push(void *item, Stack **actualStack);
void* pop(Stack **actualStack);
int getStackSize(Stack *actualStack);
Stack* deleteStack(Stack **actualStack);

Stack* initEmptyStack (int *errorCode){

    Stack* newStack = malloc(sizeof(Stack));

    if (newStack == NULL){
        *errorCode = 1;
        return NULL;
    }

    newStack->data = NULL;
    newStack->next = NULL;

    *errorCode = 0;
    return newStack;
}

int push(void *item, Stack **actualStack){

    Stack* newNode = (Stack*)malloc(sizeof(Stack));

    if(newNode == NULL){
        return 1;
    }

   newNode->data = item;
   newNode->next = *actualStack;
   *actualStack = newNode;

   return 0;

}

void* pop(Stack **actualStack){

    if (*actualStack == NULL){
        return NULL;
    }

    Stack* node = *actualStack;
    void* data = node->data;
    *actualStack = node->next;
    free(node);

    return data;

}


int getStackSize(Stack *actualStack){
    
    int count = 0;

    Stack *current = actualStack;
    
    while (current != NULL){
        current = current->next;
        count += 1;
    }

    return count;

}


Stack* deleteStack(Stack **actualStack){

    while (*actualStack != NULL) {
        pop(actualStack);
    }
    
    int errorCode;
    Stack* aNewBeginning = initEmptyStack(&errorCode);
    return aNewBeginning;
}


int main() {
    return 0;
}