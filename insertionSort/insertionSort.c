void insertionSort(int *v, int dim){
    int i, j, temp;
    for (i=1; i<dim; i++){
        temp = v[i];
        j = i-1;
        while(j>=0 && temp < v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;
    }
}