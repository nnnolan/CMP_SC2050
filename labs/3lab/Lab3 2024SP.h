#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 32


int * newBoard();

int takeShot(int *board, int cell);

int countFreeCells(int *board);

int getShotsTaken(int *board);

int getHits(int *board);

float getScore(int *board);

void updateScore(int *board);

void endGame(int *board);

