# Analisis Keamanan Program: Wood Shop (C Language)

Dokumentasi ini menjelaskan secara menyeluruh program C sederhana "Wood Shop", termasuk alur kerja, kerentanan keamanan (terutama **integer overflow**), dan cara memperbaikinya.

---

## 📄 Kode Asli

```c
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
    return 0;
}
```

## 🔍 Penjelasan Alur Program

Program ini adalah simulasi toko kayu sederhana dengan fitur:
  1. __Beli Kayu__ – Harga: 2$ per kayu.
  2. __Cek Saldo__ – Menampilkan saldo saat ini.
  3. __Keluar__ – Menghentikan program.

__Alur Eksekusi__
  1. Tampilkan menu.
  2. Baca pilihan pengguna (`1`,`2`, atau `3`).
  3. Lakukan aksi sesuai pilihan:
    * Beli kayu → hitung harga → cek saldo → kurangi jika cukup.
    * Cek saldo → tampilkan nilai `balance`.
    * Exit → hentikan loop.

---

## 🔥 Apa itu Integer Overflow?

Ketika hasil operasi aritmatika (seperti perkalian) melebihi batas maksimum tipe data, maka nilainya __wrap around__ (melompat ke nilai negatif atau tak terduga).

Pada sistem 32-bit:

`int` maksimal: __2,147,483,647__ (`INT_MAX`)
Melebihi batas → hasil menjadi __negatif__ (karena two's complement)

---

## 💣 Contoh Eksploitasi

Jika pengguna memasukkan jumlah kayu sangat besar:

```powershell
>> 1
Harga 1 kayu 2$, input jumlahnya
>> 2000000000
```

Maka:

```c
int amount = 2000000000;           // masih valid
int totalprice = 2 * 2000000000;   // = 4,000,000,000
```

Tapi:

`4,000,000,000 > INT_MAX` → overflow
Hasil: `totalprice = -294,967,296` (wrap around)