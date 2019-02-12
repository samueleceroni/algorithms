// ========================================================
// WARNING!! returns 0 if no Major Number Presence is found
// ========================================================
int majorNumberPresence(int *v, int dim){
    int i, sol, count=0;

    for (i=0; i<dim;i++){
        if(count==0){
            sol=v[i];
            count++;
        }
        else{
            if(sol==v[i])
                count++;
            else
                count--;
        }
    }

    count = 0;
    
    for (i=0; i<dim;i++){
        if(sol==v[i])
            count++;
    }

    if(count<=dim/2)
        sol = 0;

    return sol;
}