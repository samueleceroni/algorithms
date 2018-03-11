#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "is_prime.c"


int main()
{
    unsigned int num;

    printf("Inserire il numero massimo (da 2 a %lu): ", UINT_MAX);
    do
    {
        scanf("%lu", &num);
        if (num < 2 || num > ULONG_MAX)
            puts("Inserimento errato");
    } while(num < 2 || num > ULONG_MAX);

    printf("%s", (is_prime(num)?"true":"false"));

    return 0;
}


