#include <stdio.h>

// int main(){

//     char name[8];
//     char ntahlah[8] = "mizuno";
//     printf("Your name: ");
//     scanf("%s", name);
//     printf("%s\n", ntahlah);
//     printf("Hello %s, i dont listen to niggas like %s\n", name, name);

// }

int main(){
    char b[8];
    char a[8] = "123456";
    // scanf("%s", b);
    // fgets(b, 8, stdin); // variable, ukuran input, STanDart INput
    // fread(b, 1, 8, stdin); // variable, ukuran input 1*8, STanDart INput
    gets(b);
    printf("a: %s\n", a);
    printf("b: %s\n", b);
}

// nak testing tengok di gdb info fun aja si
int win(void){
    printf("ntahlah bro\n");
}

// printf tidak membaca null byte (0x00)
// scanf memiliki sifat untuk menaruh null byte (0x00) didepan string, jadi ketika input lebih dari ukuran char, maka null byte akan turun ke address di bawahnya
// fgets akan memberikan null byte (0x00) baca maksimal hanya size(index)-1, dan sisanya untuk null byte (selalu dipasang di index akhir)
// fread tidak memberikan null byte (0x00) secara otomatis ketika inputnya memenuhi dari ukuran input yang sudah ditentukan, sehingga akan menyebabkan tercampur / tersambung dengan variable berikutnya (karena tidak ada pemisah antara dua variable, yaitu null byte)
// gets tidak punya nilai batas input hingga newline (enter)


