#include <stdio.h>
#include "quickSort.c"

void printV(int *A, int p, int r){
    int i;

    for (i = p; i <=r ; i++)
        printf("%d\t", A[i]);

    printf("\n");
}

int main(){
    int A[] = {5, 3, 2, 5, 6, 3, 3, 3, 4, 1, 3, 7}, dimA = sizeof(A)/sizeof(int), i;
    srand(time(NULL));

    quickSort( A, 0, dimA-1 ); // insert the firts and the last index to be sorted

    printV(A, 0, dimA-1);
}