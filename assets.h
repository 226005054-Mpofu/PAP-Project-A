#ifndef ASSETS_H
#define ASSETS_H

extern int assetID[100];
extern char assetName[100][50];
extern char assetType[100][30];
extern float purchaseValue[100];
extern char department[100][50];
extern char assetCondition[100][30];

extern int assetCount;

void addAsset();
void displayAssets();
void searchAsset();
void assetMenu();

#endif
