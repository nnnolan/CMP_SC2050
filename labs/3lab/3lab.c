#include "Lab3 2024SP.h"

int * newBoard() {
    // i'm struggling to store the float, so i'll just make it an int for now.

    // i cant figure it out, my lapto is at 2%, pls be gracious to me TA 💔
    // im sorry

    // create a BOARD_SIZE sized array of 0's, and store some info before array 

    // we have to store before the array
    // numShots (int), numSuccesfulShots (int), and score (float), so two ints one float -> 

    int* boardArray = NULL;

    boardArray = (int *)malloc( (sizeof(int) * BOARD_SIZE ) + (sizeof(int)) + (sizeof(int)) + (sizeof(int)) ); // a bit verbose but super explicit

    // check if array is valid
    if (!boardArray){
        printf("memory error try that again boss");
    }

    // we'll store the float score  first, then num shots , then succesful shots
    // so float score -3, num shots -2, then succ shots -1
    
   // this would be a float if i could figure it out
    boardArray[0] = -15;
    boardArray++;

    // // float stored at 0, lets increase by one and turn to an int pointer
    // int* boardArrayInt = (int*)(boardArray+1);

    // store the zeros for shots and succesfful shots then increase
    boardArray[0] = 0; // shots -> boardArray[-2]
    boardArray[1] = 0; // succesful shots -> boardArray[-1];
    boardArray++;
    boardArray++;

    // init to 0, this is more safe then doing it all at once because it revolves around the #DEFINE
    for (int i =0; i < BOARD_SIZE; i++){
        boardArray[i] = 0;
    }


    return boardArray;
}

void updateScore(int *board){
    // we store succesful shots at [-1], total shots at [-2], and score at [-3]
    // score = succesful / total
    board[-3] = (float)board[-1] / (float)board[-2];

    //bingo... just yknow my score is an int </3
}

int takeShot(int *board , int cell){

    if ((board[cell] == 0) || (board[cell] == -1)){
        printf("miss ! \n");
        // update total shots, no hit
        board[-2]++;

        // score part
        void updateScore(int *board);

        return 0;
    }
    else if (board[cell] == 1) {
        printf("hit ! \n");
        
        // change cell to -1 to represnet sunk ship
        board[cell] = -1;
        
        // update shots and hits 
        board[-1]++; // succesfl shot
        board[-2]++; // total shots shot

        // score
        void updateScore(int *board);

        return 1;
    }
    else {

        printf("erorr, soemthing other than -1 0 or 1 in array or passed");
        return 5;

    }

}

int countFreeCells(int *board) {

    //loop through and if 0, add one to a sum then return that
    int sum = 0;

    for (int i =0; i < BOARD_SIZE; i++){
        if( board[i] == 0 ){
            sum++;
        }

    }

    return sum;

}

int getShotsTaken(int *board){

    // we store our total shots taken at  board[-2], so just return that
    return board[-2];

}

int getHits(int *board){

    // we store total hits at board [-1], so wej ust grab that and return
    return board[-1];
}

float getScore(int *board) {

    // get the score at [-3]
    return board[-3];
    // broken :(
}


void endGame( int* board){

    free(board-3);
    
}

