#include <stdio.h>
#include <stdlib.h>


void flip_a_coin(int *arr[], int size);


int main () {

    char Bob[3] = {'T', 'H', 'H'};
    char Alice[3] = {'H', 'H', 'T'};
    
    char coin_tosses[100] = {0};


    return 0;
}



void flip_a_coin(int *arr[], int size) {
    if (size > 100) {
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 2;
        }
    }
}