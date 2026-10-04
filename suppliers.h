#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

struct Supplier
{
    int id;
    char name[50];
    char email[50];
    char telephone[20];
    char town[30];
};
extern struct Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

int addSupplier(struct Supplier list[], int count);
void displaySuppliers(struct Supplier list[], int count);
int searchSuppliers(struct Supplier list[], int count, int id);
void compareSuppliers(struct Supplier list[], int count);
void supplierMenu(struct Supplier list[], int *count);

#endif
