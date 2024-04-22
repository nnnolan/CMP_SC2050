#include "lab11.h"

// we have the struct for car defined, lets create the struct for the db

struct Database_t {

   Car *carListByPrice;
   Car *carListBySKU;
   int totalCars;

 
}; // we can refer to as Database

// struct Car_t {
//     int SKU;
//     double price;
//     unsigned long long OEM_PN;
// };


// meat and potatoes function. this function will create a database that stores our cars
// so we have to have a structue that can efficientyl sort both by a cars price and sku, and this must run in n^2 time.
// the awkward part is that we have two keys we could sort through, and theyre not cooresponding. so sorting one is n^2, but sorting two is n^4. 
// meaning we'd have to sort both of them at the same time... 
// i guess we'd ahve two double pointers in our array

// im not sure, so lets at least sort by price first. maybe something will come up from there.
// maybe when im soritng one i do something with the other?

// wait no im an idito lmfao
// becuase we do buble sort twice its technically (n^2 * 2), whic his sitll just (n^2)
// i hope that is ture loooooooool
Database * makeDatabase(Car *cars, int size){

    Database *db = malloc(sizeof(Database));

    if (db == NULL) {
        // malloc fail
        return NULL;
    }

    db->carListByPrice = malloc(sizeof(Car) * size);
    db->carListBySKU = malloc(sizeof(Car) * size);
    
    // malloc check 
    if (db->carListBySKU == NULL || db->carListByPrice == NULL ){
        return NULL;
    }

    db->totalCars = size;

    
    // bubble sort from lecture, o(n^2)
    int violationsFound = 0;
    do {
        violationsFound = 0;
        for (int i =0; i < size-1; i++){
            
            // access cars at index i, adn the price

            // this statement executes if an out of place one is found
            if (cars[i].price > cars[i+1].price) {
                
                // swap
                Car temp = cars[i];
                cars[i] = cars[i+1];
                cars[i + 1] = temp;

                violationsFound = 1;
                

            }
    
        }
    }   
        while(violationsFound);

    db->carListByPrice = cars;


     // bubble sort from above, this time just with sku.
     // it doesn't matter that it is sorted by price rn, as that is essentialy unsorted in terms of sku
     // and we can modify cars since its relaly nbd, as it is stored else where
    do {
        violationsFound = 0;
        for (int i =0; i < size-1; i++){
            
            // access cars at index i, adn the price

            // this statement executes if an out of place one is found
            if (cars[i].SKU > cars[i+1].SKU) {
                
                // swap
                Car temp = cars[i];
                cars[i] = cars[i+1];
                cars[i + 1] = temp;

                violationsFound = 1;
                

            }
    
        }
    }   
        while(violationsFound);
        
        db->carListBySKU = cars; // bingo


    return db;

}
// sweet. that took me a while to realise that haha, but looks good to me.



// print all the skus in sorted order
// since our sku is sorted already in thes carsBySKU we are chilling. jsut follow the format and o(n) is nbd
// the last one will have the extra comma psace but high lord John said its cool
void printSKU_Sorted(Database *db) {

    printf("SKUs: ");
    for (int i =0; i<db->totalCars; i++){

        printf("%d, ", db->carListBySKU[i].SKU); // prints the SKU as "(SKU), "

    }

    printf("\n");

}

// same idea as above, copying paste this but just with formatting.
void printPriceSorted(Database *db) {

    printf("Prices: ");
    for (int i = 0; i < db->totalCars; i++ ) {

        printf("$%lf, ", db->carListBySKU[i].price); // gets the prices and prints "(NUMBER), " 
    }
    printf("\n"); // new line as specifed at the end

}


// find the associated OEM_PN from target SKU car, quick binary search
// o(logn) whic his our desired outcom yay
unsigned long long getPN_FromSKU(Database *db , int SKU) {

    int size = db->totalCars;
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        
        // hit, binary search was succesful
        if (db->carListBySKU[mid].SKU == SKU) {
            return db->carListBySKU->OEM_PN;
        }
        // target is less than mid
        else if (db->carListBySKU[mid].SKU < SKU) {
            low = mid + 1;
        } 
        
        // target is greater than mid
        else {
            high = mid - 1;
        }

    }

    // this only happens if the target is not found, because the while loop will break if low > high
    return -1;

}


// same idea as above, binary search using price as our key, and return the SKU
// so just go through the price db since thats our key
int getSKU_FromPrice(Database *db, double price){
    int size = db->totalCars;
    int low = 0;
    int mid = 0;
    int high = size - 1; // kinda verbose but oh well 

    while (low <= high) {
        mid = (low + high) / 2;
        
        // hit, binary search was succesful
        if (db->carListByPrice[mid].price == price) {
            return db->carListByPrice->SKU;
        }
        // target is less than mid
        else if (db->carListByPrice[mid].price < price) {
            low = mid + 1;
        } 
        
        // target is greater than mid
        else {
            high = mid - 1;
        }

    }

    // this only happens if the target is not found, because the while loop will break if low > high
    return -1;

}

// now we just free it all up
void destroy(Database *db){
    // we mallocd only three things so just free those things.

    free(db->carListByPrice);
    free(db->carListBySKU);
    free(db);
}

// my god
