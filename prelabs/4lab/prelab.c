#include <stdio.h>
#include <stdlib.h>


typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee;

Employee * readEmployeeArray(FILE *fp);

int main () {
    
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 1; // Return non-zero to indicate error
    }

    Employee* employeeList = readEmployeeArray(fp);

    free(employeeList);

}


Employee * readEmployeeArray(FILE *fp) {
    
    if (fp == NULL ){
        printf("error opening file");
        return 0; 
    }
    int * startArray = NULL;
    Employee * employeeArray = NULL;
    int length = 0;

    fscanf(fp, "%d", &length);
    if (fscanf(fp, "%d", &length) != 1) {
        printf("Error reading length from file");
        return NULL; // Return NULL to indicate error
    }

    // assuming we still store the length at index - 1
    // we wil ltranspose this into employee array
    startArray = (int*)malloc( ((length)  * sizeof(Employee)) + sizeof(int));

    if (!startArray){
        printf("error in memory alloc!");
        exit(1);
    }

    startArray[0] = length;

    // actual employee array
    employeeArray = (Employee*)&(startArray[1]);
    
    // read the data
    for (int i = 0; i < length; i++ ){
        fscanf(fp, "%d", &(employeeArray[i].empID));
        fscanf(fp, "%d", &(employeeArray[i].jobType));
        fscanf(fp, "%f", &(employeeArray[i].salary));
    }

    return employeeArray;


}