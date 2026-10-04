# PAP-Project-A
# Municipal Financial Management System (MFMS)
# Course: PAP521S Programming In Practice
# Project A - Foundation System

# PROJECT DESCRIPTION
This project is the foundation version of a Municipal Financial Management System. The purpose
of Project A is to apply the C programming concept covered during the first part of the course to a realistic 
municipal financial management system. The system manage information such as employees, budgets, suppliers, municipal assests
and reports.

# PROJECT STRUCTURE
    README.md
    assets.c
    assets.h
    
    budget.c
    budget.h
  
    reports.c
    reports.h
    
    suppliers.c
    suppliers.h

    validation.c
    validation.h
    
## GROUP MEMBERS AND RESPONSIBILITES

| Student Number | Name | Responsibility |
|---|---|---|
| 224056360 | Hilma Josua       | Testing, Documentation and Git Coordination  |
| 225171856 | Shaida Mutendere  | Supplier Management and README Editing       |
| 226005054 | Misela Mpho Mpofu | Asset Management                             |
| 225041758 | Laban Shishiveni  | Functions                                    |
| 226009432 | Precious Mukumba  | Reports                                      |
| 226041255 | Haimbodi Erwina   | Budget Management                            |
| 226063461 | Evelyn Muulu      | Employee Management                          |

## System Features

- Main menu with clear navigation and invalid choice handling
- Employee management: add, display, search, calculate salary
- Budget management: enter budgets and expenditure, calculate remaining budget, flag departments over budget
- Supplier management: add, display, search
- Asset management: asset register with display and search
- Reports: employee, budget, supplier and asset reports
- Input validation: rejects negative values and empty names

## Compilation Instructions

Requires GCC.

gcc -std=c99 -Wall -Wextra -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c validation.c

## How to Run

./mfms (Linux/macOS) or mfms.exe (Windows). Enter a number from the main menu to choose an option.







