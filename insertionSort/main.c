#include <stdio.h>
#include "insertionSort.c"

int main(){
    int v[]={3, 5, 9, 4, 7, 8, 6, 2, 15, 84, 45}, i, dim;

    dim = sizeof(v)/sizeof(int);
    
    insertionSort(v, dim);

    for (i=0; i<dim; i++)
        printf("%d\t", v[i]);
}