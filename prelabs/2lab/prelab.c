#include <stdio.h>
#include <stdlib.h>


float * readFloatFileIntoArray(FILE *fptr, int *length);
void freeFloatArray(float ** arrPtr);

int main() {

    FILE *fptr;

    fptr = fopen("test.txt","r");
    
    if (fptr == NULL ){
        printf("error opening file");
        return 0;
    }

    // char length = fgetc(fptr);
    // printf("%c\n", length);

    int length;

    float *floatArray = readFloatFileIntoArray(fptr, &length);

    // readFloatFileIntoArray(fptr, &length);
    if (floatArray != NULL ) {
        for (int i =0; i<length; i++){
            printf("%f ", floatArray[i]);
        }
    }
    else {
        printf("float array returned a null ! ");
    }


    freeFloatArray(&floatArray);
    fclose(fptr);

    return 0;
}


float * readFloatFileIntoArray(FILE *fptr, int *length) {

    fscanf(fptr, "%d", length);
    // printf("%d", length);


    float *array_ptr =  (float*)malloc( (sizeof(float) * (*length) ));

    if ( array_ptr == NULL ){
        printf("memory error");
        return 0;
    }

    for(int i=0; i<*length; i++){
        fscanf(fptr, "%f", &array_ptr[i]);
    }


    return array_ptr;
}

void freeFloatArray(float ** arrPtr){

    free(*arrPtr);

    *arrPtr = NULL;

}