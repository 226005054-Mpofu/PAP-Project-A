#include <stdio.h>
#include <string.h>
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void calculateSalary(Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->housingAllowance + emp->transportAllowance;
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nError: Employee database is full!\n");
        return;
    }

    Employee e;
    printf("\n--- Add New Employee ---\n");
    
    printf("Enter Employee ID: ");
    scanf("%49s", e.id);
    clearInputBuffer();

    printf("Enter Employee Name: ");
    fgets(e.name, STR_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(e.department, STR_LEN, stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    do {
        printf("Enter Basic Salary (N$): ");
        if (scanf("%lf", &e.basicSalary) != 1 || e.basicSalary < 0) {
            printf("Invalid input. Basic salary must be non-negative.\n");
            clearInputBuffer();
            e.basicSalary = -1;
        }
    } while (e.basicSalary < 0);

    do {
        printf("Enter Housing Allowance (N$): ");
        if (scanf("%lf", &e.housingAllowance) != 1 || e.housingAllowance < 0) {
            printf("Invalid input. Housing allowance must be non-negative.\n");
            clearInputBuffer();
            e.housingAllowance = -1;
        }
    } while (e.housingAllowance < 0);

    do {
        printf("Enter Transport Allowance (N$): ");
        if (scanf("%lf", &e.transportAllowance) != 1 || e.transportAllowance < 0) {
            printf("Invalid input. Transport allowance must be non-negative.\n");
            clearInputBuffer();
            e.transportAllowance = -1;
        }
    } while (e.transportAllowance < 0);

    calculateSalary(&e);
    employees[employeeCount++] = e;

    printf("Employee added successfully!\n");
}

void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("\nNo employees recorded in the system.\n");
        return;
    }

    printf("\n====================================================================================================\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross Pay");
    printf("====================================================================================================\n");

    for (int i = 0; i < employeeCount; i++) {
        printf("%-10s %-20s %-20s N$%-10.2f N$%-10.2f N$%-10.2f N$%-10.2f\n",
               employees[i].id, employees[i].name, employees[i].department,
               employees[i].basicSalary, employees[i].housingAllowance,
               employees[i].transportAllowance, employees[i].grossSalary);
    }
    printf("====================================================================================================\n");
}

void searchEmployee(void) {
   if (employeeCount == 0) {
        printf("\nNo employees available to search.\n");
        return;
    }

    char searchKey[STR_LEN];
    printf("\nEnter Employee ID or Name to Search: ");
    clearInputBuffer();
    fgets(searchKey, STR_LEN, stdin);
    searchKey[strcspn(searchKey, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].id, searchKey) == 0 || strstr(employees[i].name, searchKey) != NULL) {
            printf("\n--- Match Found ---\n");
            printf("ID: %s\nName: %s\nDepartment: %s\nBasic Salary: N$%.2f\nHousing: N$%.2f\nTransport: N$%.2f\nGross Salary: N$%.2f\n",
                   employees[i].id, employees[i].name, employees[i].department,
                   employees[i].basicSalary, employees[i].housingAllowance,
                   employees[i].transportAllowance, employees[i].grossSalary);
            found = 1;
        }
    }

    if (!found) {
        printf("No employee matching '%s' was found.\n", searchKey);
    }
}