#include <stdio.h>
#include "tests.h"
#include "validation.h"
#include "budget.h"

void runTests(void)
{
    printf("\n===== SYSTEM TESTING =====\n");

    /* Test ID validation */
    printf("Valid ID: %s\n",
           validateID(10) ? "PASS" : "FAIL");

    printf("Invalid ID: %s\n",
           !validateID(-5) ? "PASS" : "FAIL");

    /* Test money validation */
    printf("Valid money: %s\n",
           validateMoney(500.00) ? "PASS" : "FAIL");

    printf("Invalid money: %s\n",
           !validateMoney(-100.00) ? "PASS" : "FAIL");

    /* Test text validation */
    printf("Valid text: %s\n",
           validateText("Finance") ? "PASS" : "FAIL");

    printf("Empty text: %s\n",
           !validateText("") ? "PASS" : "FAIL");

    /* Test email validation */
    printf("Valid email: %s\n",
           validateEmail("student@nust.na") ? "PASS" : "FAIL");

    printf("Invalid email: %s\n",
           !validateEmail("studentnust.na") ? "PASS" : "FAIL");

    /* Test phone validation */
    printf("Valid phone: %s\n",
           validatePhone("+264 81 123 4567") ? "PASS" : "FAIL");

    printf("Invalid phone: %s\n",
           !validatePhone("abc123") ? "PASS" : "FAIL");

    /* Test budget calculation */
    Budget testBudget;

    testBudget.allocatedBudget = 10000.00;
    testBudget.expenditure = 7500.00;

    calculateBudgetStatus(&testBudget);

    printf("Budget remaining calculation: %s\n",
           testBudget.remainingBudget == 2500.00 ? "PASS" : "FAIL");

    printf("Budget exceeded status: %s\n",
           testBudget.isExceeded == 0 ? "PASS" : "FAIL");

    /* Test exceeded budget */
    testBudget.allocatedBudget = 5000.00;
    testBudget.expenditure = 6000.00;

    calculateBudgetStatus(&testBudget);

    printf("Exceeded budget detection: %s\n",
           testBudget.isExceeded == 1 ? "PASS" : "FAIL");

    printf("==========================\n");
}