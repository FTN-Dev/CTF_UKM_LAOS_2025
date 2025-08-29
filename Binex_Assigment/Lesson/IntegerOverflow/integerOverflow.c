#include <stdio.h>

void menu(){
    puts("Welcome to the wood shop!");
    puts("1. Buy Wood");
    puts("2. Check Balance");
    puts("3. Exit");
    printf(">> ");

}

int main(){
    int balance = 10;
    while(1){
        menu();
        int choice;
        scanf("%d", &choice);
        if (choice == 1){
            int amount;
            puts("Harga 1 kayu 2$, input jumlahnya");
            printf(">> ");
            scanf("%d", &amount);
            int totalprice = 2 * amount;
            if( totalprice < balance ){
                balance -= totalprice;
                puts("udh kebeli nigga!");
            }
            else{
                puts("minggir lu miskin!");
            }
        }
        else if (choice == 2) {
            printf("You have %d$\n\n", balance);
        }
        else if (choice == 3) {
            break;
        }
    }
}