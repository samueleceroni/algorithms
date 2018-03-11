
int maxVector_rec(int *v, int dim){

    int m1, m2;

    if (dim == 1)
        return *v;
    else{

        m1 = maxVector_rec(v, dim/2);
        m2 = maxVector_rec(v + dim/2, (dim+1)/2);   // (dim+1) takes advatage of implicit casting

        return (m1>m2 ? m1 : m2);
    } 

}