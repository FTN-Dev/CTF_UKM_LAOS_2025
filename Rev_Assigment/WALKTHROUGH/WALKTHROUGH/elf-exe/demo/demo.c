#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char input[23];
	char correct[23] = "CIE_LAGI_LIAT_SLIDES_GW";
	puts("What's the secret?");
	scanf("%23s",input);
	if(strcmp(input,correct)){
		puts("Wrong, you're such a noob, please just don't focus on RE, you are better in misc category");
	} else{
		puts("Oh cool , it's correct! Now what? What did you learn from here? Nothing");
	}

	return 0;
}