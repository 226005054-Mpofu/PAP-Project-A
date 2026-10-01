#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "employees.h"

Budget budgets[MAX_DEPARTMENTS];
int budgetCount = 0;

void calculateBudgetStatus(Budget *b) {
    b->remainingBudget = b->allocatedBudget - b->expenditure;
    b->isExceeded = (b->remainingBudget < 0) ? 1 : 0;
}

void manageBudgets(void) {
    if (budgetCount >= MAX_DEPARTMENTS) {
        printf("\nError: Maximum department limit reached.\n");
        return;
    }

    Budget b;
    printf("\n--- Departmental Budget Entry ---\n");
    clearInputBuffer();

    printf("Enter Department Name: ");
    fgets(b.departmentName, STR_LEN, stdin);
    b.departmentName[strcspn(b.departmentName, "\n")] = '\0';

    do {
        printf("Enter Allocated Budget (N$): ");
        if (scanf("%lf", &b.allocatedBudget) != 1 || b.allocatedBudget < 0) {
            printf("Invalid budget amount. Enter a non-negative number.\n");
            clearInputBuffer();
            b.allocatedBudget = -1;
        }
    } while (b.allocatedBudget < 0);

    do {
        printf("Enter Total Expenditure (N$): ");
        if (scanf("%lf", &b.expenditure) != 1 || b.expenditure < 0) {
            printf("Invalid expenditure amount. Enter a non-negative number.\n");
            clearInputBuffer();
            b.expenditure = -1;
        }
    } while (b.expenditure < 0);

    calculateBudgetStatus(&b);

    int foundIndex = -1;
    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].departmentName, b.departmentName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        budgets[foundIndex] = b;
        printf("Successfully updated budget for %s!\n", b.departmentName);
    } else {
        budgets[budgetCount++] = b;
        printf("Budget entry successfully recorded!\n");
    }
}

void displayBudgets(void) {
    if (budgetCount == 0) {
        printf("\nNo departmental budget records available.\n");
        return;
    }

    printf("\n====================================================================================\n");
    printf("%-20s %-18s %-18s %-18s %-12s\n", "Department", "Allocated (N$)", "Expenditure (N$)", "Remaining (N$)", "Status");
    printf("====================================================================================\n");

    for (int i = 0; i < budgetCount; i++) {
        printf("%-20s N$%-16.2f N$%-16.2f N$%-16.2f %-12s\n",
               budgets[i].departmentName,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               budgets[i].remainingBudget,
               budgets[i].isExceeded ? "OVER BUDGET" : "WITHIN BUDGET");
    }
    printf("====================================================================================\n");
}