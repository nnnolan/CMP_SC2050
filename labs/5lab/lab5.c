#include "lab5.h"


struct VendingMachine_t {

    //this is the structure of our vending machine

    int occupiedSlots; // occupied slots, shows how many items are being stored 
    int numMaxSlots;  // num of maximum slots, the upper limit

    // this is the complex part...
    // we are going to create a list of pointers type stock item, that will point to items
    StockItem** listOfItemPointers; // trust the process ^_^

};

VendingMachine * newMachine(int numSlots) {

    // were going to create a vending machine data type

    // this inits everything rather straight forward
    VendingMachine *wipVendingMachine = malloc(sizeof(VendingMachine));
    wipVendingMachine->occupiedSlots = 0;
    wipVendingMachine->numMaxSlots = numSlots;

    // lets init our array holdign the actual items though
    // this creates enough room for our list
    wipVendingMachine->listOfItemPointers = malloc(sizeof(StockItem*) * numSlots);

    // check if malloc failed
    if (!wipVendingMachine->listOfItemPointers){
        //printf("malloc error\n");
        return NULL;
    }

    // now lets init everything in item to 0
    for (int i=0; i<numSlots; i++){

        // grab the current item
        StockItem *curr = wipVendingMachine->listOfItemPointers[i];

        // now set everything about it to 0
        curr->ID = 0;
        curr->maxStock = 0;
        curr->price = 0;
        curr->stock =0;

    }

    // else we're all good
    return wipVendingMachine;

    // bingo
}

int addStockItem(VendingMachine *vm, StockItem item){

    // we shall first check for some index issues
    if (vm->occupiedSlots >= vm->numMaxSlots) {
        // printf("there are greater than or equal to occupied slots than max slots.")
        //return 0 as directed
        return 0;
    }


    /* 
    this is where it gets silly 

    on our list of pointers to items, we are going to take the first free index
    then we are going to set that first free index to a pointer that points this item 

    check if its an error, then if we're good, set that pointer equal to the item

    i dont know if this is the inteded way to do it but shrug looool
    
    */
    vm->listOfItemPointers[vm->occupiedSlots] = malloc(sizeof(StockItem));

    if(!vm->listOfItemPointers[vm->occupiedSlots]){
        // malloc error
        return 0;
    }

    // set the slot to item, we are in pointers now
    *vm->listOfItemPointers[vm->occupiedSlots] = item; 
    // increase occ slots
    vm->occupiedSlots++;

    // return 1 for success
    return 1;
}

int countExpensive(VendingMachine *vm){

    int count = 0;

    // coun the items in the vending machine that are >= 3 smackaroos
    for (int i=0; i < (vm->occupiedSlots);i++){
        // in the loop, lets go through each item
        // even if there isnt max slots, it'll still be 0'd
        if (vm->listOfItemPointers[i]->price >= 3){
            count++;
        }
        
    }

    return count;
}

void freeVendingMachine(VendingMachine *vm) {

    // so we have a pointer to a list of pointers

    // we will tackle the  pointers inside the list first, freeing those
    for (int i =0; i<(vm->numMaxSlots);i++){

        free(vm->listOfItemPointers[i]);

    }
    // now the list pointer
    free(vm->listOfItemPointers);

    // and finally the vending machine itself
    free(vm);
    // fire

}

