#include "lab4.h"


GameBoard * newBoard() {

    // we shall create a new gameboard, and init everything to 0's

    // init our structure, malloc covers all size issues for the two ints, array, and float
    GameBoard * finalBoardPointer = malloc(sizeof(GameBoard));

    // safety
    if (!finalBoardPointer) {
        printf("yo your memory is messed up, heres a null pointer \n");
        return NULL;
    }


    // lets make sure our board is clear
    for (int i =0; i<BOARD_SIZE;i++){
        finalBoardPointer->arena[i] = 0;
    }

    // aswell as everything else (i dont know if this is necessary but prob good practice)
    finalBoardPointer->hits=0;
    finalBoardPointer->shots=0;
    finalBoardPointer->score=0.0;


    // send it back
    return finalBoardPointer;

}

int takeShot(GameBoard *board, int cell){

    // take shot, and if the cell is has a 1 in it, we note that as a hit
    // return 1 on a hit, 0 on a miss

    if (board->arena[cell] == 1) {
        printf("Hit!\n");

        board->hits++; //increase hits and shots by one since we have a hit
        board->shots++; // shots !

        // score is defined by hits/shots
        board->score = ( (board->hits) / (board->shots));

        // 1 indicates a hit
        return 1;
    }
    else if (board->arena[cell] == 0 || board->arena[cell] == -1){
        printf("miss! or it was an already destroyed ship!\n");

        board->shots++; // increase shots

        // do the score part again
        board->score = ( ( (board->hits) / (board->shots) ) );

        // return 0 for a missed shot
        return 0;
    }

    // i don't think this ever happens but just for security
    else { 
        printf("something went horribly wrong\n");
        return 369;
    }
}


int countRemainingShips(GameBoard * board){

    // count how many ships are left in the arena
    // this can be achieved by iterating through the list, counting everytime theres a 1
    // and then subtracting that sum for BOARD_SIZE

    int count = 0;

    for (int i =0; i<BOARD_SIZE; i++){

        if (board->arena[i] == 1) {
            count++;
        }

    }

    // return it back, could you do this in one line?
    // return board_size - count?
    int final = BOARD_SIZE - count;
    return final;

}

int getShotsTaken(GameBoard * board){

    // return the amount of shots taken, which is stored in the struct
    // super free

    return board->shots;

}

int getHits(GameBoard *board) {

    // return the hits, which is stored in struct
    // like get shotstaken, so free

    return board->hits;

}

float getScore(GameBoard *board){

    // return score, defined in struct

    return board->score;
}

int placeShip(GameBoard *board, int cell){

    // we allow the user to place cell
    // also assumes cell is a valid pos in the board (said in zoom comments)

    // if it is already occupied or destroyed, return 0
    // else we change the cell to 1 and return 1

    if (board->arena[cell] == 0) {
        printf("ship placed at cell %d! \n", cell);
        board->arena[cell] = 1;
        return 1;
    }

    else if (board->arena[cell] == 1 || board->arena[cell] == -1) {
        printf("cell is already occupied or destroyed at %d! nothing placed \n", cell);
        return 0;
    }

    else {
        // again jus security, dont think itll ever be here
        printf("something went wrong");
        return 40;
    }

}
void endGame(GameBoard *board){

    // simply just free the board
    // it is a pointer so this is rudimentary 
    free(board);

    // so long space cowboy
}
// yknow, it is starting to click 

