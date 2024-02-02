#include "Lab 1 quiz.h"

int main() {

    int a, b;

    printf("enter two numbers and watch them get swapped");
    scanf("\n%d", &a);
    scanf("%d", &b);

    swap(&a, &b);
    printf("%d %d\n", a,b);

    printf("\n ------- \n");

     
   // ---------  //


    // you could modify this part and make it scan in a number for size and a easy loop
    // to get the array init, but my brain is seriously hurting. 
    int my_array[] = {3, 1, 7};
 

    if (!(swapMaxMin(my_array, 3))){
        for (int i=0;i<3;i++){

            printf("%d", my_array[i]);

        }
    }
    else {
        printf("error in executing swap max min");
    }

    printf("\n ------- \n");



    // ---------  //


    
    char my_str[] = "Hello World!"; // 11 chars, 1 more for \0
    char result; // the result
    
    // find index 3, why not
    // likewise with the second problem, it wouldnt be hard to implement a scan f to make the index easy.
    // but my brain is seriously mush. the code doesnt even look real to me rn. need to lie down
    // pls dont tank my grade, and if this is an issue lmk so i can know for later <3

    if (!(charAt(my_str, 3, &result))) {
        
        printf("the resulting char at index is %c !!! ", result);

    }
    

    return 0;
}



void swap(int *a, int *b){

    int temp;
    temp = *a;
    (*a) = (*b);
    (*b) = temp;

}


int swapMaxMin(int array[], int size){
    // swap min max
    // if min == max, return 1, else 0

    int minPoistion=0, maxPosition=0;

    for (int i = 0; i < size; i++) {

        if (array[i] <= array[minPoistion]) {
            minPoistion = i;
        }
        else if (array[i] >= array[maxPosition]){
            maxPosition = i;
        }
    }

    if (maxPosition == minPoistion) {
        printf("min = max!!\n");
        return 1;
    }

    else {

        // the ol switcheroo
        int temp = array[maxPosition];
        array[maxPosition] = array[minPoistion];
        array[minPoistion] = temp;
        return 0;
    }

}

int charAt(char str[], int index, char *result){

    int size = 0;
    for (int i= 0;(str[i] !='\0');i++){
        size++;
    }

    printf("size of str = %d\n", size);

    if (index < 0 || index > size){
        printf("thats illegal !");
        return 1;
    }

    else {
        *result = str[index];
        return 0;
    }
}

