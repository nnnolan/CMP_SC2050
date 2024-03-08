#include <stdlib.h>
#include <stdio.h>

typedef struct nstruct {
    int key;
    struct nstruct *next;
} Node;


int main() {
    // Node myNode, *yourNode;

    // Node *p = NULL;
    

    // int myKey = (*p).key;



    int *p=NULL, n=5;
    *p = n;

    *p = 2;

    printf("%d",n);



    return 0;
}