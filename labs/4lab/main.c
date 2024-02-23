#include "lab4.h"

int main() {

    GameBoard* myBoard = NULL;
    myBoard = newBoard();

    if(!takeShot(myBoard, 2)){
        printf("updated\n");
    }
    printf("%d\n", myBoard->shots);

    endGame(myBoard);

    return 0;
}