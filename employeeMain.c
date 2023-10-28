//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 
#include <stdlib.h>  
#include "employee.h" 

int main(void)
{ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumToFind); 
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind); 

    //defined in employeeTable.c 
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 
    
    //Example not found 
    if(matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if(matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");  

    // Search Phone Number: found 
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if(matchPtr != NULL) 
        printf("Employee with number 909-555-1234 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with number 909-555-1234 is NOT found in the record\n"); 
    
    // : not found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-0000");
    if(matchPtr != NULL) 
        printf("Employee with number 909-555-0000 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with number 909-555-0000 is NOT found in the record\n"); 

    // Search Salary : found 
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78); 
    if (matchPtr != NULL) 
        printf("Employee salary 8.78 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary 8.78 is NOT found in the record\n");

    // : not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.90); 
    if (matchPtr != NULL) 
        printf("Employee salary 6.90 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary 6.90 is NOT found in the record\n");

    return EXIT_SUCCESS; 
} 