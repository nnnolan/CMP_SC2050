#include <stdio.h>
#include <stdlib.h>

int my_function(int arr_size, int my_array[], int target);


int main() { 

    int arr_size = 5;
    int my_array[] = {1, 2, 3, 4, 5};
    int target = 3;

    int count = my_function(arr_size, my_array, target);

    printf("The number of times %d appears in the array is %d\n", target, count);
    
    return 0;

}

int my_function(int arr_size, int my_array[], int target) {

    int i;
    int count;
    for (i = 0; i < arr_size; i++) {
        if (my_array[i] == target) {
            count += 1;
        }
    }
    return count;
}
