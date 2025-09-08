#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FILE_NAME "products.csv"

typedef struct {
    char name[50];
    char cuid[20];
    char status[20];
} Product;

//新增產品 
void addProduct() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter CUID: ");
    scanf("%s", p.cuid);
    strcpy(p.status, "InProgress");

    fprintf(file, "%s,%s,%s\n", p.name, p.cuid, p.status);
    fclose(file);

    printf("Product added successfully!\n");
}

//產品列表 
void listProducts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }

    char line[200];
    printf("\n=== Product List ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

//更新狀態 
void updateStatus() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }

    Product products[100];
    int count = 0;
    while (fscanf(file, "%49[^,],%19[^,],%19[^\n]\n",
                  products[count].name,
                  products[count].cuid,
                  products[count].status) == 3) {
        count++;
    }
    fclose(file);

    char target[20];
    printf("Enter CUID to update: ");
    scanf("%s", target);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].cuid, target) == 0) {
            printf("Current status: %s\n", products[i].status);
            printf("Enter new status: ");
            scanf("%s", products[i].status);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("CUID not found.\n");
        return;
    }

    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s\n", products[i].name,
                products[i].cuid, products[i].status);
    }
    fclose(file);

    printf("Status updated successfully!\n");
}

//搜尋產品 
void searchProduct() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }

    char target[20];
    printf("Enter CUID to search: ");
    scanf("%s", target);

    Product p;
    int found = 0;
    while (fscanf(file, "%49[^,],%19[^,],%19[^\n]\n",
                  p.name, p.cuid, p.status) == 3) {
        if (strcmp(p.cuid, target) == 0) {
            printf("\n=== Product Found ===\n");
            printf("Name: %s\n", p.name);
            printf("CUID: %s\n", p.cuid);
            printf("Status: %s\n", p.status);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("CUID not found.\n");
    }

    fclose(file);
}


int main() {
    SetConsoleOutputCP(65001); // 設定輸出為 UTF-8
    SetConsoleCP(65001);       // 設定輸入為 UTF-8
 
    int choice;
    while (1) {
        printf("1) Add product\n");
        printf("2) Update status by CUID\n");
        printf("3) List all products\n");
        printf("4) Search product by CUID\n");
        printf("5) Exit\n");
  
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: updateStatus(); break;
            case 3: listProducts(); break;
            case 4: searchProduct(); break;
            case 5: exit(0);

            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

