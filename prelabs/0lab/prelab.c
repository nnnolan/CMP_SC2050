#include <stdio.h>
#include <stdlib.h>

/* compile using -wall -werror -Wpendantic flags */


int my_function(int arr_size, int my_array[], int target);
void my_function_ptr(int *arr_size_ptr, int *my_array_ptr, int *target_ptr, int *count_ptr);



int main() { 

    int arr_size = 5;
    int my_array[] = {1, 2, 3, 4, 5};
    int target = 3;

    int count = my_function(arr_size, my_array, target);

    printf("The number of times %d appears in the array is %d\n", target, count);
    

    // this time with pointers
    count = 0;

    int *arr_size_ptr = &arr_size;
    int *my_array_ptr = my_array;
    int *target_ptr = &target;
    int *count_ptr = &count;


    my_function_ptr(arr_size_ptr, my_array_ptr, target_ptr, count_ptr);
    printf("The number of times %d appears in the array is, as declraed by the void function is :%d\n", target, count);

    
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

void my_function_ptr(int *arr_size_ptr, int *my_array_ptr, int *target_ptr, int *count_ptr){

    int i;
    int local_count;

    for (i = 0; i < *arr_size_ptr; i++) {
        if (my_array_ptr[i] == *target_ptr) {
            local_count += 1;
        }
    }
    
    *count_ptr = local_count; // this is the same as count = local_count
}