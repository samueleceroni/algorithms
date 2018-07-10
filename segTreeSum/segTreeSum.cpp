#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
//Segment tree per range-sum su liste di interi con point update.
struct SumSegmentTree {
    private:
    vector<int> v; // vettore che contiene l'albero
    int n; //numero nodi interni
    const int NULL_VALUE = 0; //zero dell'operazione
    public:
    SumSegmentTree(int num) {
        v.resize((1 << (int)(ceil(log2(num))+1))-1, NULL_VALUE);//completo bilanciato
        n = v.size() / 2;
    }

    SumSegmentTree(vector<int> &source) {
        v.resize((1 << (int)(ceil(log2(source.size()))+1))-1, NULL_VALUE);//completo bilanciato
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
        v[i] = mergeValues(v[left(i)], v[right(i)]);
    }

    int rangeQuery(int i, int l, int r, int a, int b) {
        if (l >= a && r <= b) {
            return v[i];
        }
        if (r < a || l > b) {
            return NULL_VALUE;
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
    public:

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
                cout << v[i] << " ";
                i++;
            }
            livNum *= 2;
            cout << "\n";
        }
    }
};
