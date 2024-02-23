#include "lab5.h" 

int main () {

    VendingMachine* vendingMachinePtr = NULL;

    vendingMachinePtr = newMachine(40);

    printf("%d", vendingMachinePtr->numMaxSlots);

    freeVendingMachine(vendingMachinePtr);

    return 0;
}