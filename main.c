#include <stdio.h>

#include "assets.h"
#include "budget.h"
#include "employees.h"
#include "suppliers.h"
#include "reports.h"
#include "validation.h"


void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("        EMPLOYEE MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}


int main(void)
{
    int choice;

    do
    {
        printf("\n");
        printf("==============================================\n");
        printf("     MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("==============================================\n");
        printf("1. Asset Management\n");
        printf("2. Budget Management\n");
        printf("3. Employee Management\n");
        printf("4. Supplier Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("==============================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                assetMenu();
                break;

            case 2:
                manageBudgets();
                break;

            case 3:
                employeeMenu();
                break;

            case 4:
                supplierMenu(suppliers, &supplierCount);
                break;

            case 5:
                displayReports();
                break;

            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                printf("Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}