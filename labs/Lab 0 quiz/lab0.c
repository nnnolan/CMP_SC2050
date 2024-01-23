#include "lab0.h"

/* REQUIRED CODE GOES HERE */
// create a function that counts for certian target number

int countOccurrences(int size, int my_array[], int query){

    int count = 0;

    for(int i = 0; i<size; i++ ){

        if (my_array[i] == query) {
            count++;
        }

    }

    return count;


}

/*
 pls let me know if this doesnt work
im getting a silly error that didnt happen when i used any compiler online
error: linker command failed with exit code 1 (use -v to see invocation)

(base) nolanpestano@mwc-069254 Lab 0 quiz % gcc main.c
ld: Undefined symbols:
  _countOccurrences, referenced from:
      _main in main-57a710.o ????????

save me from this hell known as c programming 🙏
*/
