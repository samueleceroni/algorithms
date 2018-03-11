#include <stdio.h>
#include "maxVector_rec.h"

int main(){
    int v[]={0, 50, 9, 6, 7, 1, 3, 5, 18, 3}, sol;

    sol = maxVector_rec(v, sizeof(v)/sizeof(int));

    printf("%d", sol);

}
