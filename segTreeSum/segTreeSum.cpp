#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
//Segment tree per range-sum su liste di interi con point update.
struct SumSegmentTree {
    private:
    vector<int> v; // vettore che contiene l'albero
    vector<int> u; // vettore che contriene l'update
    int n; //numero nodi interni
    const int NULL_VALUE = 0; //zero dell'operazione
    public:
    SumSegmentTree(int num) {
        v.resize((1 << (int)(ceil(log2(num))+1))-1, NULL_VALUE);//completo bilanciato
        u.resize((1 << (int)(ceil(log2(num))+1))-1, NULL_VALUE);//completo bilanciato
        n = v.size() / 2;
    }

    SumSegmentTree(vector<int> &source) {
        v.resize((1 << (int)(ceil(log2(source.size()))+1))-1, NULL_VALUE);//completo bilanciato
        u.resize((1 << (int)(ceil(log2(source.size()))+1))-1, NULL_VALUE);//completo bilanciato
        n = v.size() / 2;
        for (int i = 0; i < source.size(); i++) {
            v[i + n] = source[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            updateNode(i);
        }
    }
    private:
    int left(int i) {
        return i*2+1;
    }

    int right(int i) {
        return i*2+2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int mergeValues(int v1, int v2) {
        return v1 + v2;
    }

    void updateNode(int i) {
        if(!isLeave(i))
            v[i] = mergeValues(v[left(i)], v[right(i)]);
    }

    int rangeQuery(int i, int l, int r, int a, int b) {
        if (r < a || l > b) {
            return NULL_VALUE;
        }

        v[i] += u[i];
        if(!isLeave(i)){
            u[(left(i))] += u[i]/2;
            u[(right(i))] += u[i]/2;
        }
        u[i] = NULL_VALUE;

        if (l >= a && r <= b) {
            return v[i];
        }

        int m = (l + r) / 2;
        return mergeValues(rangeQuery(left(i), l, m, a, b), rangeQuery(right(i), m + 1, r, a, b));
    }

    void updateToRoot(int i) {
        updateNode(i);
        if (i != 0) {
            updateToRoot(parent(i));
        }
    }

    bool isLeave(int i){
        return i>v.size()/2;
    }

    void rangeUpdateQuery(int i, int l, int r, int a, int b, int value){

        if (l >= a && r <= b){
            if (!isLeave(i)){
                u[left(i)]=value * (r-l+1)/2;
                u[right(i)]=value * (r-l+1)/2;
            }
            v[i] += value * (r-l+1);
            updateToRoot(parent(i));
            return;
        }
        if (r<a || l>b){
            return;
        }
        //v[i] += value * (b-a+1); // add to current node the value *number of leaves in the range of nodes i'll have to update
        int m = (l + r) / 2;
        rangeUpdateQuery(left(i), l, m, a, b, value);
        rangeUpdateQuery(right(i), m + 1, r, a, b, value);    
        
    }


    public:
    
    void rangeUpdate(int a, int b, int value){
        rangeUpdateQuery(0,0, n, a, b, value);
    }


    int rangeSum(int a, int b) {
        return rangeQuery(0, 0, n, a, b);
    }

    void update(int index, int value) {
        int i = n + index;
        v[i] = value;
        updateToRoot(parent(i));
    }

    void print() {
        int i = 0;
        int livNum = 1;
        while (i < v.size()) {
            for (int j = 0; j < livNum; j++) {
                cout << v[i] << " (" <<u[i]<<") ";
                i++;
            }
            livNum *= 2;
            cout << "\n";
        }
    }
};

int main() { // main di test della struttura
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    SumSegmentTree st(v);
    st.print();
    cout << st.rangeSum(0, 3) << ' ' << st.rangeSum(2, 5) << '\n';
    st.update(3, 5);
    st.print();
    cout << st.rangeSum(0, 3) << ' ' << st.rangeSum(2, 5) << '\n';
    st.rangeUpdate(3, 5, 100);
    st.print();
    cout << st.rangeSum(0, 3) << ' ' << st.rangeSum(2, 5) << '\n';
    

    return 0;
}
