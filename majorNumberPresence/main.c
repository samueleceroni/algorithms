#include <stdio.h>
#include "majorNumberPresence.c"

int main(){

    int v[]={3, 4, 3, 2, 1, 3, 6, 3, 3}, sol;

    sol = majorNumberPresence(v, sizeof(v)/sizeof(int)); // WARNING!! returns 0 if no Major Number Presence is found

    printf("%d", sol);
}
