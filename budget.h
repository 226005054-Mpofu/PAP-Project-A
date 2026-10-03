#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 50
#define STR_LEN 50

typedef struct {
    char departmentName[STR_LEN];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
    int isExceeded;
} Budget;

extern Budget budgets[MAX_DEPARTMENTS];
extern int budgetCount;

void calculateBudgetStatus(Budget *b);
void manageBudgets(void);
void displayBudgets(void);

#endif