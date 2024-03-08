#include "lab7.h"


VendingMachine * newMachine ();
int addStockItem(VendingMachine *vm , StockItem item);
int countItems(VendingMachine *vm);
int countEmpty(VendingMachine *vm);
int getStockItem(VendingMachine *vm , int ID, StockItem *result);
void freeVendingMachine(VendingMachine *vm);

// start by finishing vending machine struct
struct VendingMachine_t {

    // each slots have to hold a stock item
    
    //reading over it, vending machien is our "node" and our "data" is just a slot item
    // so one instance of the stock, and then one pointer to next vendingmachine
    StockItem itemInStock;
    VendingMachine *next;

};



VendingMachine * newMachine() {
    // we'll create a new machine, and init everything

    VendingMachine* myMachine = malloc(sizeof(VendingMachine));

    // check for malloc erorr
    if(!myMachine) {
        return NULL;
    }


    // null to represent the end
    myMachine->next = NULL;

    // this is just to show this item present has no usage. i am a bit iffy on using this but i just want to be sure that it is explicit that this is nothing
    // lab actually says return an *empty* struct, so here is this 
    myMachine->itemInStock.ID = -1;
    myMachine->itemInStock.maxStock = -1;
    myMachine->itemInStock.price = -1;
    myMachine->itemInStock.stock = -1;


    return myMachine;

}

int addStockItem(VendingMachine *vm , StockItem item){
    // add a stock item, return 0 on a failure and 1 on a success
    // also assume never a duplicate whcih is nice

    // so we have to create a new vendignmachine struct, and chagne our *vm's (the one passed) next to the address of this one 

    VendingMachine *newItem = malloc(sizeof(item));

    // check for malloc error
    if (!newItem){
        return 0;
    }

    // set our passed item to the item present in our pointer
    newItem->itemInStock = item;

    // change our pointers in the passed vending machine
    // this is the linked list part
    // also set newitem next to null to represent the end
    vm->next = newItem;
    newItem->next = NULL;


    // we take that
    return 1;
}

int countItems(VendingMachine *vm){
    // count the items present in the vedning machine regardless of the stock

    int count = 0;
    VendingMachine *temp = vm;


    // we are gonna traverse the linked list until we find a null, which signifies the end
    // we use a temp as to not mess with the actual struct
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // we are gonna subtract one because this currently counts the head as having an item, which it doesnt as noted by the implementation
    count = count - 1;

    // return the items
    return count;

}

int countEmpty(VendingMachine *vm) {
    // count the amount of empty slots in our machine
    
    int count = 0;
    VendingMachine *temp = vm; 

    // we are gonna use a very similiar idea to countItems(), just we have to check if temp->iteminstock.stock = 0 before adding 1 to count

    while (temp != NULL) {

        // checks for a zero, could use a ! but i prefer the explicit
        if( (temp->itemInStock.stock) == 0) {
            count ++;
        }    

    temp = temp->next;

    }

    return count;
}

int getStockItem(VendingMachine *vm , int ID, StockItem *result) {
    // we are going to find the item stocked with id, ID
    // like the past two funcs, we r gonna loop to a temp
    // and we are gonna check if temp->item.id == our id
    // return 1 and update pointer on a success, return 0 on failure (not gonna touch pointer bc no mention)

    VendingMachine *temp = vm; 
    
    while (temp != NULL) {

        if( (temp->itemInStock.ID) == ID ){
            // hit
            *result = temp->itemInStock;
            return 1;
        }
        // else keep going
        temp = temp->next;
    }

    // if we reached this point, no bites
    return 0;
}


void freeVendingMachine(VendingMachine *vm){
    // close our vending machines, free the memory
     // we have to use a secondary pointer to be careful to not lose any links
    VendingMachine* tempRemoval = vm;


    while(vm != NULL){

        tempRemoval = vm; // store the temporary
        vm = vm->next; // move the actual pointer onwards
        free(tempRemoval); // free the temporary

    }

    // nuthin to return ^_^

}

// im so good
