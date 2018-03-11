#include <stdio.h>
#include "mergeSort.c"

int main(){
    int v[]={0, 3, 5, 8, 2, 4, 9, 6, 7};
    mergeSort(v,0,8);
    for (int i=0; i<(sizeof(v)/sizeof(v[0])); i++)
        printf("%d", v[i]);
}