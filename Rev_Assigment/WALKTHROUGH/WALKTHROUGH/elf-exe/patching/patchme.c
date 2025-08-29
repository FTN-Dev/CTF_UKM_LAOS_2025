#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	puts("Program ini harus tunggu 2 jam supaya bisa jalan!");
	sleep(7200);
	char changeme[] = "Pacaran yuk!";
	int changethis = 2000;
	if(strcmp(changeme, "Nikah yuk!") && changethis != 1337) {
		puts("Kamu dapet pacar baru tapi dia selingkuh mulu!");
		exit(-1);
	} else {
		puts("Kamu balikan sama mantan dan semesta merestui kalian mencintai hingga akhir hayat!");
	}
	return 0;
}