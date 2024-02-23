#include "lab5.h" 

int main () {

    VendingMachine* vendingMachinePtr = NULL;

    vendingMachinePtr = newMachine(40);
    // #include "lab5.h"

    #include "lab5.h"

    printf("%d", vendingMachinePtr->numMaxSlots);

    freeVendingMachine(vendingMachinePtr);

    return 0;
}