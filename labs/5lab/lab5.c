#include "lab5.h"

typedef struct VendingMachine_t VendingMachine;

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

    // init each slot to hold an item
    for (int i = 0; i<numSlots; i++){
        wipVendingMachine->listOfItemPointers[i] = malloc(sizeof(StockItem));
        
        // also check for malloc fails
        if (!wipVendingMachine->listOfItemPointers[i]){
            return NULL;
        }
    }

    // check if malloc failed
    if (!wipVendingMachine->listOfItemPointers){
        //printf("malloc error\n");
        return NULL;
    }

    // now lets init everything in item to 0
    for (int i=0; i<numSlots; i++){

        // now set everything about it to 0
        // could use a pointer but nbd
        wipVendingMachine->listOfItemPointers[i]->ID = 0;
        wipVendingMachine->listOfItemPointers[i]->maxStock = 0;
        wipVendingMachine->listOfItemPointers[i]->price = 0;
        wipVendingMachine->listOfItemPointers[i]->stock =0;

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

   // i thik this below commented out code isnt neede anymore
    // vm->listOfItemPointers[vm->occupiedSlots] = malloc(sizeof(StockItem));

    // if(!vm->listOfItemPointers[vm->occupiedSlots]){
    //     // malloc error
    //     return 0;
    // }

    // set the slot to item, we are in pointers now
    *vm->listOfItemPointers[vm->occupiedSlots] = item; 
    // increase occ slots
    vm->occupiedSlots++;

    // return 1 for success
    return 1;
}

int removeStockItem(VendingMachine *vm , int ID, StockItem *result) {
    
    // lets find hte item with id ID
    for (int i=0;i<vm->numMaxSlots;i++){

        if (vm->listOfItemPointers[i]->ID == ID){
            // we found it 
            // instrucitons really only say we need to empty it, no need to overengineer htis tbh

            vm->listOfItemPointers[i]->ID = 0;
            vm->listOfItemPointers[i]->stock = 0;
            vm->listOfItemPointers[i]->maxStock = 0;
            vm->listOfItemPointers[i]->price = 0;

            // we return pointer to this empty place
            StockItem emptyReuslt = *(vm->listOfItemPointers[i]);
            *result = emptyReuslt;

            //successful
            return 1;
        }

    }
    // no bites, return 0
    return 0;


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

