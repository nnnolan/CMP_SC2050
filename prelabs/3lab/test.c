#include <stdlib.h>
#include <stdio.h>

int * createIntArray(FILE *fptr, int *length);
float getArrayMean(int*);
void freeIntArray(int*);

int main () {
    FILE *fptr;

    fptr = fopen("test.txt","r");
    
    if (fptr == NULL ){
        printf("error opening file");
        return 0;
    }

    int length = 0;

    int *intArray = createIntArray(fptr, &length);

    printf("Mean of the array: %.2f\n", getArrayMean(intArray));

    fclose(fptr);
    freeIntArray(intArray);

    return 0;
}

int * createIntArray(FILE *fptr, int *length) {
    int* array = NULL;
    int sum = 0;
    *length = 0;

    
    fscanf(fptr, "%d", length);
    // Allocate memory for the array
    array = (int *)malloc((*length) * sizeof(int));
    if (!array){
        printf("error in memory alloc!");
        exit(1);
    }
  
    // Read data from file into the array
    for (int i = 0; i < *length; i++) {
        if (feof(fptr)) {
            *length = i;
            break;
        }
        fscanf(fptr, "%d", &(array[i]));
        sum += array[i];
    }

    // Calculate mean and store it at the end of the array
    float mean = (float)sum / *length;
    *((float*)(array + *length)) = mean;

    return array;
}

float getArrayMean(int* arr){
    // Retrieve mean stored at the end of the array
    return *((float*)(arr + *(((int*)arr)-1)));
}

void freeIntArray(int* arr){
    free(arr);
}
