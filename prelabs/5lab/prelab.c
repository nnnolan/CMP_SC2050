#include <stdlib.h> 
#include <stdio.h>
#include <string.h>



typedef struct {

    int maxLength;
    int currentLength;
    char** list;

} GroceryList;

GroceryList GroceryListInit(int maxLength, int *errorCode);
GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode);
char * GroceryListGetItem(GroceryList glist, int k, int *errorCode);
int GroceryCount(GroceryList);
void GroceryListPrint(GroceryList);
void GroceryListDelete(GroceryList);


GroceryList GroceryListInit(int maxLength, int *errorCode){

    *errorCode = 1;

    GroceryList gList;

    gList.currentLength = 0;
    gList.maxLength = maxLength;

    // set up the char array 
    gList.list = malloc(sizeof(char*) * maxLength);
    if (!gList.list) {
        gList.list = NULL;
        return gList;
    }

    *errorCode = 0;

    return gList;

}

GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode) {

    *errorCode = 1;

    if (glist.currentLength >= glist.maxLength) {

        printf("at list's max length\n");
        return glist;
    }

    glist.list[glist.currentLength] = malloc(sizeof(char)*strlen(itemName) + 1);

    if (!glist.list[glist.currentLength]) {
        printf("malloc failed on new str");
        return glist;
    }
    
    strcpy(glist.list[glist.currentLength++], itemName);

    *errorCode = 0;

    return glist;

}

void GroceryListDelete (GroceryList glist){

    for (int i =0; i< glist.currentLength;i++){

        free(glist.list[i]);

    }
    free(glist.list);

}

char * GroceryListGetItem(GroceryList glist, int k, int *errorCode){

    *errorCode = 1;

    if( k > glist.maxLength || k> glist.currentLength || k <= 0){
        printf("index out of bounds");
        return NULL;
    }

    else {
        
        *errorCode = 0;
        char* str = glist.list[k];
        printf("returning str at index %d : %s\n", k, str);
        return str;

    }

}

int GroceryCount(GroceryList glist){
    printf("current count = %d\n", glist.currentLength);
    return glist.currentLength;
}


void GroceryListPrint(GroceryList glist){
    for (int i = 0; i<glist.currentLength; i++) {
        printf("%s\n", glist.list[i]);
    }
}


int main() {

    int errorCode = 0;
    GroceryList myList = GroceryListInit(40, &errorCode);
    if (errorCode){
        printf("something went wrong\n");
    }
    else{
        printf("my list ! max length = %d\n", myList.maxLength);
    }

    GroceryListDelete(myList);

    return 0;
}