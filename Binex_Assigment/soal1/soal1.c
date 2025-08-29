#include <stdio.h>
#include <stdlib.h>

#define VIP_THRESHOLD 10000000

void vip_club() {
    char flag[64];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL) {
        printf("Flag file not found.\n");
        exit(1);
    }
    fgets(flag, sizeof(flag), f);
    printf("%s\n", flag);
    fclose(f);
}

int main() {
    int balance = 1000;
    int prices[] = {10, 20, 500000};
    int choice;
    int quantity;

    printf("Welcome to the Underground Shop!\n");
    printf("You currently have %d coins.\n", balance);

    while (1) {
        printf("\n1. Buy Bread (10 coins)\n");
        printf("2. Buy Milk (20 coins)\n");
        printf("3. Buy Diamond (500000 coins)\n");
        printf("4. View Balance\n");
        printf("5. Enter VIP Club\n");
        printf("6. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                if (quantity <= 0) {
                    printf("Invalid quantity!\n");
                    break;
                }
                int price = prices[choice - 1];
                int total_cost = price * quantity;

                if (total_cost > balance) {
                    printf("Not enough balance!\n");
                } else {
                    balance -= total_cost;
                    printf("You bought %d items. New balance: %d\n", quantity, balance);
                }
                break;
            case 4:
                printf("Current balance: %d coins\n", balance);
                break;
            case 5:
                if (balance >= VIP_THRESHOLD) {
                    printf("Welcome to the VIP club! Here's your flag: ");
                    vip_club();
                    exit(0);
                } else {
                    printf("You need at least %d coins to enter the VIP club.\n", VIP_THRESHOLD);
                }
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}