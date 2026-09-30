#include <stdio.h>
#include <string.h>

int assetID[100];
char assetName[100][50];
char assetType[100][30];
float purchaseValue[100];
char department[100][50];
char assetCondition[100][30];

int assetCount = 0;

void addAsset(){

    if (assetCount >= 100)
    {
        printf("\nMaximum limit reached. Cannot add more assets.\n");
        return;
    }

    printf("\n========== ADD ASSET ==========\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assetID[assetCount]);
    while (getchar() != '\n');

    printf("Enter Asset Name: ");
    fgets(assetName[assetCount], sizeof(assetName[assetCount]), stdin);
    assetName[assetCount][strcspn(assetName[assetCount], "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assetType[assetCount], sizeof(assetType[assetCount]), stdin);
    assetType[assetCount][strcspn(assetType[assetCount], "\n")] = '\0';

    printf("Enter Purchase Value: ");
    scanf("%f", &purchaseValue[assetCount]);
    while (getchar() != '\n');

    printf("Enter Department: ");
    fgets(department[assetCount], sizeof(department[assetCount]), stdin);
    department[assetCount][strcspn(department[assetCount], "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assetCondition[assetCount], sizeof(assetCondition[assetCount]), stdin);
    assetCondition[assetCount][strcspn(assetCondition[assetCount], "\n")] = '\0';

    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(){

    if (assetCount == 0)
    {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n========== REGISTERED ASSETS ==========\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("-----------------------------\n");

        printf("Asset ID: %d\n", assetID[i]);
        printf("Asset Name: %s\n", assetName[i]);
        printf("Asset Type: %s\n", assetType[i]);
        printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
        printf("Department: %s\n", department[i]);
        printf("Condition: %s\n", assetCondition[i]);
    }
}

void searchAsset(){

    int searchID;
    int found = 0;

    if (assetCount == 0)
    {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n========== SEARCH ASSET ==========\n");

    printf("Enter Asset ID to search: ");
    scanf("%d", &searchID);
    while (getchar() != '\n');

    for (int i = 0; i < assetCount; i++)
    {
        if (assetID[i] == searchID)
        {
            printf("\nAsset Found!\n");
            printf("-----------------------------\n");

            printf("Asset ID: %d\n", assetID[i]);
            printf("Asset Name: %s\n", assetName[i]);
            printf("Asset Type: %s\n", assetType[i]);
            printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
            printf("Department: %s\n", department[i]);
            printf("Condition: %s\n", assetCondition[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAsset not found.\n");
    }
}

void assetMenu(){

    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       ASSET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1-4.\n");
        }

    } while (choice != 4);
}

int main(void){

    assetMenu();

    return 0;
}