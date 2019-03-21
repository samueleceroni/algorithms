#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

#define tt int //it can be changed to char, short, long long
#define NULL_VALUE 0

struct SSTNode {
    tt val;
    SSTNode* left;
    SSTNode* right;
    pair<int,int> range;
};

struct SST {

    SSTNode* head;

    private:
    
    tt merge(tt val1, tt val2){
        return val1 + val2;
    }

    int queryRange(int l, int r, const SSTNode* n) {
        if(!n) return NULL_VALUE;
        if(n->range.first >= l && n->range.second <= r) {
            return n-> val;
        }
        if(n->range.second < l || n->range.first > r) {
            return NULL_VALUE;
        }
        return merge(queryRange(l, r, n->left), queryRange(l, r, n->right));
    }

    void print(SSTNode* n){
        if(!n) return;
        cout << n -> range.first << ' ' << n -> range.second << ": " << n->val << endl;
        print(n -> left);
        print(n -> right);
    }

    SSTNode* buildTree(const vector<tt>& v, int l, int r) {
        if(l == r)
            return new SSTNode{v[l], nullptr, nullptr, {l, r}};
        int mid = l + (r-l)/2;
        SSTNode* n1 = buildTree(v, l, mid);
        SSTNode* n2 = buildTree(v, mid + 1, r);
        return new SSTNode{merge(n1->val, n2->val), n1, n2, {l, r}};
    }

    public:

    SST(const vector<tt>& v){
        this -> head = buildTree(v, 0, v.size()-1);
    }

    tt queryRange(int l, int r) {
        return queryRange(l, r, head);
    }

    void print(){
        print(this -> head);
    }
    
};


int main(){
    vector<tt> v {1, 2, 3, 4};
    SST m = SST(v);
    m.print();
    cout << m.queryRange(0, 2) << endl;
}