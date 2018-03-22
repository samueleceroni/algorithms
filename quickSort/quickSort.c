#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r){
    
    int pi, pv, i=l, j=r; //pivotIndex, pivotValue, indexToLeft, indexToRight

    pi = rand()%(r-l+1) + l;
    pv = arr[pi];

    while(i<j){
        if(arr[j]>=pv)
            j--;
        else if (arr[i]>= pv)
            swap(arr+i,arr+j);
        else
            i++;
    }

    if(arr[i]<=pv)
        return i;
    else
        return i-1;
}

void quickSort(int *A, int l, int r){

    if (l < r){
        int q = partition(A, l, r);
        quickSort(A, l, q);
        quickSort(A, q+1, r);
    
    }
}

