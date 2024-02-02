#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses) {
    // Step 1: Error Checking
    for (int i = 0; i < 3; i++) {
        if (player1[i] != 'H' && player1[i] != 'T') {
            return 1; // Error code 1: Invalid character in player 1's sequence
        }
        if (player2[i] != 'H' && player2[i] != 'T') {
            return 2; // Error code 2: Invalid character in player 2's sequence
        }
    }

    // Step 2: Simulation
    int toss;
    int tosses[3]; // To store the last 3 tosses for comparison
    *numTosses = 0;

    srand(time(NULL)); // Seed the random number generator

    do {
        // Simulate a single coin toss
        toss = rand() % 2;
        tosses[*numTosses % 3] = toss; // Store the toss for comparison
        (*numTosses)++;

        // Check if the current toss matches player 1's sequence
        if (tosses[0] == (player1[0] == 'H') && tosses[1] == (player1[1] == 'H') && tosses[2] == (player1[2] == 'H')) {
            *winner = 1; // Player 1 wins
            return 0;    // Success
        }

        // Check if the current toss matches player 2's sequence
        if (tosses[0] == (player2[0] == 'H') && tosses[1] == (player2[1] == 'H') && tosses[2] == (player2[2] == 'H')) {
            *winner = 2; // Player 2 wins
            return 0;    // Success
        }

    } while (1); // Continue until a winner is determined
}

int main() {
    char aliceSequence[3] = {'H', 'H', 'T'};
    char bobSequence[3] = {'T', 'H', 'H'};
    int winner, numTosses;
    int aliceWins = 0, bobWins = 0;
    int simulations = 1000000; // You can adjust the number of simulations

    for (int i = 0; i < simulations; i++) {
        int result = coinTossGame(aliceSequence, bobSequence, &winner, &numTosses);
        if (result == 0) {
            if (winner == 1) {
                aliceWins++;
            } else {
                bobWins++;
            }
        } else {
            printf("Error %d occurred during simulation.\n", result);
        }
    }

    // Step 7: Analysis
    double aliceWinPercentage = (double)aliceWins / simulations * 100;
    double bobWinPercentage = (double)bobWins / simulations * 100;

    printf("Alice's winning percentage: %.2f%%\n", aliceWinPercentage);
    printf("Bob's winning percentage: %.2f%%\n", bobWinPercentage);

    return 0;
}
