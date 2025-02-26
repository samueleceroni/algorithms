void merge (int arr[], int l, int m, int r){

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[i + l];

    for (j = 0; j < n2; j++)
        R[j] = arr[j + m + 1];

    i=0;
    j=0;
    k=l;

    while (i<n1 && j< n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++]=L[i++];
    
    while (j < n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if (l<r){
        
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}