#include "lab2.h"


int * makeArray(int size) {

    /* we'll create an array of size n, where n = size (array of size size :P)
    we want to return the pointer, a malloc. and then init 0 */

    int *array_ptr =  (int *)malloc( sizeof(int) * size); 


    // check if malloc failed-- malloc returns null on failed exec
    if (array_ptr == NULL) {
        printf("error in malloc in makeArray\n");
        return NULL;
    }

    // i think calloc returns a full init zero array, but i dont remember. better just to make sure its 0
    for (int i =0; i < size; i++){
        array_ptr[i] = 0;
    }

    return array_ptr;
    
}

int * addressOf(int *array, int size, int element){

    // find the address of target int, assume no duplicates
    // loop through array looking for element
    for (int i = 0; i < size; i++) {

        if (array[i] == element) { //bingo
            printf("match found, location on array : %d. returning address of array[%d]\n", i, i);
            return &array[i];
        }
    }

    // we reutrn null if no bites
    printf("failed to find target query in array, returning null \n");
    return NULL;
}

int sliceArray(int *array, int size, int begin, int end, int **result){

    /* 
        moddify the *array as directed by the slice indexes, and we'll return the new size

        we can use our two previous functions to help here
        but just need to work at it tbh, slice functions are pretty common and explanatory 
    */

   // lets check to see if both end points are valid first
   // we'll store begin and end as beginIndex and endIndex respectively
    int *beginAddress = addressOf(array, size, begin); 
    int *endAddress = addressOf(array, size, end);

   if ( (beginAddress == NULL) || (endAddress == NULL) ) {
        // if beginIndex is false OR endIndex is false, then at least one is missing. return -1 as directed by high lord prof uhlman
        printf("one or both indexes not found !");
        return -1;
    }


    int beginIndex = *beginAddress;
    int endIndex = *endAddress;



    // so now we have both indexes. we still have to slice the index. so we can start from the bottom index and stop at the top index.
    // can just use the derefrence address , as if end index is 9 and begin index is 3, then 9-3 = 6, size of our  final array size
    int finalArraySize = endIndex-beginIndex;
    
    // we'll create an array of size finalArraySize
    int *finalArray = makeArray(finalArraySize);

    // now we steal values from the first array and populate final array with them
    for (int i = 0; i<finalArraySize; i++){
        finalArray[i] = beginAddress[i];
    }
    
    // point the first index of final array to result
    *result = &finalArray[0];
    // return size of arary
    return finalArraySize;
}

// nice to just have this cooldown. sotlen from prelab.
void freeArray(int **array){

    free(*array);
    *array = NULL;
}

// jesus this is only the second lab.

