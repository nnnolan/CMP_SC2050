#include <stdio.h>
#include <stdlib.h>

typedef struct Employee_t {

    int ssn;
    int id;

} Employee;

typedef struct EmpDatabase_t {

    Employee **dataBase; 
    int errorCode;

} EmpDatabase;


EmpDatabase createSearchableEmployeeDB(Employee **, int);
Employee * findEmpBySSN(int targetSSN, EmpDatabase);
Employee * findEmpByID(int targetID, EmpDatabase employeeDB);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);
Employee * RECURSIVEfindEmpBySSN(int targetSSN, EmpDatabase employeeDB, int low, int high);

EmpDatabase createSearchableEmployeeDB(Employee ** passedDoubleArray, int sizeOfArray){

    EmpDatabase db; 
    db.errorCode = 0;

    int *dataBase = malloc( (sizeof(Employee) * sizeOfArray ) + sizeof(int));
    
    if (dataBase == NULL){
        printf("malloc fail");
        db.errorCode = 1;
        return db;
    }

    dataBase[0] = sizeOfArray;
    db.dataBase = (Employee **)(dataBase+1);

    for (int i =0; i<sizeOfArray; i++){
        db.dataBase[i] = passedDoubleArray[i];
    }
    
    return db; 
}

Employee * findEmpBySSN(int targetSSN, EmpDatabase employeeDB) {

    // binary search
    if (employeeDB.dataBase == NULL){
        employeeDB.errorCode = 1;
        return NULL;
    }

    int size = *((int*)employeeDB.dataBase - 1);
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        
        // hit, binary search was succesful
        if (employeeDB.dataBase[mid]->ssn == targetSSN) {
            return employeeDB.dataBase[mid];
        }
        // target is less than mid
        else if (employeeDB.dataBase[mid]->ssn < targetSSN) {
            low = mid + 1;
        } 
        
        // target is greater than mid
        else {
            high = mid - 1;
        }

    }

    // this only happens if the target is not found, because the while loop will break if low > high
    return NULL;
    

}

Employee * findEmpByID(int targetID, EmpDatabase employeeDB) {
    // same thing, except we are searching by ID
    // literally copy and paste the above function and change the ssn to id

    // binary search

    int size = *((int*)employeeDB.dataBase - 1);
    int mid = 0;
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        
        // hit, binary search was succesful
        if (employeeDB.dataBase[mid]->ssn == targetID) {
            return employeeDB.dataBase[mid];
        }
        // target is less than mid
        else if (employeeDB.dataBase[mid]->ssn < targetID) {
            low = mid + 1;
        } 
        
        // target is greater than mid
        else {
            high = mid - 1;
        }

    }

    // this only happens if the target is not found, because the while loop will break if low > high
    return NULL;
    

}

void freeEmpDatabase(EmpDatabase eDatabase) {
    free((int*)eDatabase.dataBase - 1); // Free the entire block, including the integer storing size

    // Free each individual Employee structure
    for (int i = 0; i < *((int*)eDatabase.dataBase - 1); i++) {
        free(eDatabase.dataBase[i]);
    }

}


int main() {


    Employee *emp1 = malloc(sizeof(Employee));
    emp1->ssn = 123456789;
    emp1->id = 1;

    Employee *emp2 = malloc(sizeof(Employee));
    emp2->ssn = 987654321;
    emp2->id = 2;

    Employee **empArray = malloc(sizeof(Employee *) * 2);
    empArray[0] = emp1;
    empArray[1] = emp2;

    EmpDatabase db = createSearchableEmployeeDB(empArray, 2);

    Employee *foundEmp = findEmpBySSN(123456789, db); // should return emp1
    // debug
    if (foundEmp == NULL){
        printf("employee not found\n");
        // why is it not found?
    }
    else printf("employee found by ssn: %d\n", foundEmp->id);
    // printf("employee found by ssn: %d\n", foundEmp->id);


    // freeEmpDatabase(db);


    return 0;
}