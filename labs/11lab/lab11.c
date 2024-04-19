#include "lab11.h"

// we have the struct for car defined, lets create the struct for the db

struct Database_t {

   Car **carList;
   int totalCars;

}; // we can refer to as Database

// struct Car_t {
//     int SKU;
//     double price;
//     unsigned long long OEM_PN;
// };


// meat and potatoes function. this function will create a database that stores our cars
// sso we have to have a structue that can efficientyl sort both by a cars price and sku, and this must run in n^2 time.
// the awkward part is that we have two keys we could sort through, and theyre not cooresponding 
Database * makeDatabase(Car *cars, int size);