#include <stdio.h>
#include <stdlib.h>


typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee;

Employee * readEmployeeArray(FILE *fp);
Employee * getEmployeeByID(Employee *, int empID);
int setEmpSalary(Employee *, int empID, float salary);
int getEmpSalary(Employee *, int empID, float *salary);
int setEmpJobType(Employee *, int empID, int job);
int getEmpJobType(Employee *, int empID, int *job);
void freeEmployeeArray(Employee * employeeArray);

int main () {
    
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1; // return one to indicate error
    }

    Employee* employeeList = readEmployeeArray(fp);

    freeEmployeeArray(employeeList);

    return 0;
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

Employee * getEmployeeByID(Employee * employeeArray, int empID){

    int length = *((int*)employeeArray - 1); // Retrieve the length from the previous integer
    for (int i = 0; i<length; i++){

        if(employeeArray[i].empID == empID) {
            return &employeeArray[i];
        }

    }

    // assuming we dont find it
    return NULL;
}

int setEmpSalary(Employee * employeeArray, int empID, float salary) {

    Employee *employee = getEmployeeByID(employeeArray, empID);

    if(employee != NULL) {
        employee->salary = salary;
        return 0;
    }
    // when we don't find the emp
    else {
        return 1;
    }

}

int getEmpSalary(Employee * employeeArray, int empID, float *salary){

    Employee *employee = getEmployeeByID(employeeArray, empID);

    if(employee != NULL) {
        *salary = employee->salary;
        return 0;
    }

    else{
        return 1;
    }
}
int setEmpJobType(Employee * employeeArray, int empID, int job){

    Employee *employee = getEmployeeByID(employeeArray, empID);

    if(employee != NULL) {
        employee->jobType = job;
        return 0;
    }

    // when we don't find the emp
    else {
        return 1;
    }
}


int getEmpJobType(Employee * employeeArray, int empID, int *job){

    Employee *employee = getEmployeeByID(employeeArray, empID);

    if(employee != NULL) {
        *job = employee->jobType;
        return 0;
    }

    else{
        return 1;
    }

}

void freeEmployeeArray(Employee * employeeArray) {

    free(employeeArray);
    employeeArray = NULL;
}
