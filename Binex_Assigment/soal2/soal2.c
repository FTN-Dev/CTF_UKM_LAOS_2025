#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_password(char *password) {
    srand(time(0));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 16; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
}

void print_flag() {
    char flag[64];
    FILE *f = fopen("flag.txt", "r");
    if (!f) {
        perror("Failed to open flag");
        exit(1);
    }
    fgets(flag, sizeof(flag), f);
    printf("VIP Flag: %s\n", flag);
    fclose(f);
}

int main() {
    char password[16];
    generate_password(password); // Generate password at startup
    
    char username[16];
    int username_length;
    printf("Welcome to Overflow Boutique!\n");
    printf("Enter username length: ");
    scanf("%d\n", &username_length);
    
    printf("Enter your username: ");
    fread(username, 1, username_length, stdin);

    printf("\n--- User Profile ---\n");
    printf("Username: %s\n", username);

    printf("\nEnter the secret password to unlock VIP: ");
    char input[16];
    fgets(input, 16, stdin);
    printf("input: %s\n", input);

    if (strcmp(input, password) == 0) {
        print_flag();
    } else {
        printf("Access Denied!\n");
    }

    return 0;
}