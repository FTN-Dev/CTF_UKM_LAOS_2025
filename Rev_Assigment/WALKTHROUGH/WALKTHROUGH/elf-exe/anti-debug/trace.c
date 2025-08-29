#include <stdio.h>
#include <sys/ptrace.h>

int main()
{
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) 
    {
        printf("Ih lagi nge debug gue yah? Pergi sono\n");
        return 1;
    }
    
    printf("Seru banget hari ini sama kalian! Untung kamu lagi engga ngedebug aku!\n");
    return 0;
}