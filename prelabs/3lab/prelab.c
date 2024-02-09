#include <stdlib.h>
#include <stdio.h>


int * createIntArray(FILE *fptr, int *length);
float getArrayMean(int*);
void freeIntArray(int*) ;


int main () {

    FILE *fptr;

    fptr = fopen("test.txt","r");
    
    if (fptr == NULL ){
        printf("error opening file");
        return 0;
    }

    int length = 0;

    int *intArray = createIntArray(fptr, &length);

    printf("%d", intArray[-1]);


    fclose(fptr);
    // freeIntArray(intArray);


    return 0;
}

int * createIntArray(FILE *fptr, int *length) {
    int* array = NULL;
    float mean, sum;
    *length = 0;

    fscanf(fptr, "%d", length);
    printf("size of array to be createid is %d\n", *length);

    // extra size of int to hide one inside
    array = (int *)malloc((*length) * sizeof(int) + sizeof(float)); // Allocate memory for the array

    if (!array){
        printf("error in memory alloc!");
    }
  

    // now we read data from file into the array
    // so user can access length array at index[-1]
    for (int i = 0; i<((*length)); i++) {
        
        if (feof(fptr)) {
            *length = (1-i);
            break;
        }

        // this happens awlays if ^ isnt true
        fscanf(fptr, "%d", &(array[i]));
        sum += array[i];
    }

    // assign array 0 it
    ((float*)array)[0] = (((float)sum) / (float)*length);

    return array;
}



float getArrayMean(int* arr){
    return *((float*)arr - 1);
}

void freeIntArray(int* arr){

    free(arr -1);
}
