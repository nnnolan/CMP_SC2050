#include "lab5.h" 

typedef struct VendingMachine_t VendingMachine;

int main () {

    VendingMachine * vendingMachinePtr = NULL;

    vendingMachinePtr = newMachine(40);

    printf("type : %p", (void*)vendingMachinePtr);
    StockItem myItem = {1, 2, 3,4};

    if(addStockItem(vendingMachinePtr, myItem)){
        printf("hello");
    }


\
    int expensive = countExpensive(vendingMachinePtr);

    printf("expensive %d", expensive);

    

    freeVendingMachine(vendingMachinePtr);
    

    return 0;
}