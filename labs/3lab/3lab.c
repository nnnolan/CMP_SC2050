#include "Lab3 2024SP.h"

int main() {
    int * newboard = NULL;

    newboard = newBoard();
    printf("%f", (float)newboard[0]);

    free(newboard-2);

    return 0;
}

int * newBoard() {

    // create a BOARD_SIZE sized array of 0's, and store some info before array 

    // we have to store before the array
    // numShots (int), numSuccesfulShots (int), and score (float), so two ints one float -> 

    int* boardArray = NULL;

    boardArray = (int *)malloc( (sizeof(int) * BOARD_SIZE ) + (sizeof(int)) + (sizeof(int)) + (sizeof(float)) ); // a bit verbose but super explicit

    // check if array is valid
    if (!boardArray){
        printf("memory error try that again boss");
    }

    // we'll store num shots first, then succesful shots, then the float score... 
    // so numShots is at boardArray[-3]. succesfulShots[-2], score[-1]
    
    boardArray[0], boardArray[1] = 0;
    boardArray++;
    boardArray++;

    float test = 40.005;
    // so now we have a sizeof(int) * board_size array, + memory for a float
    ((float*)boardArray)[0] = test;

    return boardArray;


}