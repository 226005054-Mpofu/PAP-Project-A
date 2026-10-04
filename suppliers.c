#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int addSupplier(struct Supplier list [], int count)
{
  int i, id, duplicate;
   if( count >= MAX_SUPPLIERS)
{
   printf("\nSorry,the supplier list is full.\n");
    return 0;
}
do
{
   duplicate = 0;
   printf{"Enter Supplier ID: ");
    scanf("%d", &id);
    while (getchar() != '\n');

   if(id <= 0)
{
    printf("ID must be a positive number.\n");
     duplicate = 1;
}
else
{
   for(i = 0; i < count; i++)
{
    if( list[i].id == id);
{
     printf("That ID is already used. Try again.\n");
     duplicate = 1;
      break;
}
}
}
}
  while (duplicate == 1);
list[count].id = id;

printf("Enter Supplier Name: ");
    fgets(list[count].name, 50, stdin);
    list[count].name[strcspn(list[count].name, "\n"] = '\0';

if(strlen(list[count].name) == 0
{
    printf('Name cannot be empty.\n");
    return 0;
}
 printf("Enter Email: ");
fgets(list[count].email, 50,stdin);
list[count].email[strcspn(list[count].email, "\n")] = '\0';

if(strlen(list[count].email, '@') == NULL)
{
   printf("Email must contain '@'.\n");
    return 0;
}
printf("Enter Telephone Number: ");
fgets(list[count].telephone, 20, stdin);
    list[count].telephone[strcspn(list[count].telephone, "\n")] = '\0';

if(strlen(list[count].telephone) < 7)
{
  printf("Telephone number is too short.\n");
  return 0;
}
printf("Enter Town/Location: ");
    fgets(list[count].town, 30, stdin);
    list[count].town[strcspn(list[count].town, "\n")] = '\0';
if(strlen(list[count].town) == 0
}
printf("Town can not be empty.\n");
return 0;
}
printf("\nSupplier added successfully.\n");
}
void displaySupplier(struct Supplier list[], int count)
{
  int i;

if(count == 0)
{
      printf("\nNo suppliers to display.\n");
}
  printf("\n--------------------------\n);
  printf("%-5s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Telephone", "Town");
   printf("\n---------------------------\n);

     for(i = 0; i < count; i++)
     {
        printf("%-5d %-20s %-25s %-15s %-15s\n", list[i].id, list[i].name, list[i].email, list[i].telephone, list[i].town);

   }
      printf("----------------------------\n);
        printf("Total suppliers: %d\n", count);
}
int searchSuppliers(struct suppliers list[], int count, int id)
{
  int i;

for(i = 0; i< count; i++)
{
   if(list[i].id == id)
{
   return i;
}
}
return -1;
}
void compareSuppliers(struct Suppliers list[], int count)
{
       int id1, id2, i1, i2;

  if(count < 2)
{
   printf("\nYou need at least 2 suppliers to compare.\n");
    return;
}
printf("Enter first Supplier ID: ");
  scanf("%d", &id1);
    while (getchar() != '\n');

printf("Enter second Supplier ID: ");
scanf("%d", &id2);
    while (getchar() != '\n');

i1 = searchSupplier(list, count, id1);
i2 = searchSupplier(list, count,id2);

if(i1 == -1 && i2 == -1)
{
   printf("\nOne or both supplier IDs were not found.\n");
   return;
}
printf(\n------------COMPARISON-------------\N");
printf("&-12s %-20s %-20s\n", "FIELD", "SUPPLIER 1", "SUPPLIER 2");
printf("------------------------------------\n);
printf("%-12s %-20d %-20d\n", "ID", list[i1].id, list[i2].id);
printf("%-12s %-20s %-20s\n", "NAME", list[i1].name, list[i2].name);
printf("%-12s %-20s %-20s\n", "EMAIL", list[i1].email, list[12].email);
printf("%-12s %-20s %-20s\n", "TELEPHONE", list[1i1].telephone, list[i2].telephone);
printf("%-12s %-20s %-20s\n", "TOWN", list[i1].town, list[i2].town);
printf("--------------------------------------\n");

if(strcmp(list[i1].town, list[i2].town) == 0)
{
   printf("Both suppliers are in the same town.\n);
     }
     else
     {
        printf("Suppliers are in different towns.\n");
     }
}

void  supplierMenu(struct supplier list[], int * count)
{
  int choice;
  int id, index;

do
{
  printf("\n======= SUPPLIER MANAGEMENT =======\n");
  printf("1. Add Supplier\n");
  printf("2. Display Supplier\n");
  printf("3. Search Supplier\n");
  printf("4. Compare Supplies\n");
   printf("5. Back to Main Menu\n");
   printf("Choose an option: ");
   scanf("%d", &choice);
    while (getchar() 1= '\n');

switch (Choice)
{
case 1:
    if(addSupplier(list, *count) == 1)
{
   (*count)++;
}
break;

case 2:
displaySuppliers(list, *count);
break;

case 3:
   if(*count == 0)
{
   printf("\nNo suppliers to search: \n");
   scanf("%d", &id);
    while(getchar() != '\n');

   index = searchSupplier(list, *count, id):

     if(index == -1)
{
   printf("\nSupplier with ID %d was not found.\n", id);
}
else
{
  printf("\nSupplier found: \n");
  printf("ID        :%d\n", list[index].id);
  printf("Name      :%d\n", list[index].name);
  printf("Email     :%d\n",  list[index].email);
  printf("Telephone :%s\n",  list[index].telephone);
  printf("Town      :%s\n",  list[index].town);
}
break;

case 4:
   compareSuppliers(list, *count);
   break;

case 5:
   printf("\Returning to main menu...\n");
break;

deafault:
     printf("\nInvalid choice. Please try again.\n");
}
}
}
  while (choice != 5);

int main(void)

   struct Supplier suppliers[MAX_SUPPLIERS];
  int supplierCount = 0;
   int choice;
do
{
   printf("\n======== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM =========\n");
   printf("1. Supplier Management\n");
   printf("2. Exit\n");
   printf("Choose an option:  ");
    scanf("%d", %choice):

      switch (choice)
{
case 1:
    supplierMenu(supplers, &supplierCount);
   break;

case 2:
   printf("\nGoodbye!\n");
   break;

default:
 printf("\nInvalid choice. Try again. \n");
}
}
  while(choice != 2);

return 0;
}
