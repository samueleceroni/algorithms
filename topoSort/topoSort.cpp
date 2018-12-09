#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visit(int currNode, const vector<vector<int> > & g, vector<int> &sol, vector<int> &marks){
    if(marks[currNode] == 2){return true;}
    if(marks[currNode] == 1){return false;} // not a DAG
    marks[currNode] = 1;
    for(auto nextNode : g[currNode]){
        bool ok = visit(nextNode, g, sol, marks);
        if(!ok){return false;}
    }
    marks[currNode] = 2;
    sol.push_back(currNode);
    return true;
}

vector<int> topoSort(const vector<vector<int> > &g){
    vector<int> marks(g.size(), 0);
    vector<int> sol;
    for(auto nextEl : marks){
        if(!visit(nextEl, g, sol, marks)){return vector<int>();}
    }
    reverse(sol.begin(), sol.end());
    return sol;
}

int main()
 {
    int n, e;
    int start, end;
    cin >> n >> e;

    vector<vector<int> > g(n);
    for(int i = 0; i < e; i++){
        cin >> start >> end;
        g[start].push_back(end);
    }
    vector<int> topoSorted = topoSort(g);

    for(int el : topoSorted){
        cout << el << ' ';
    }
    cout << endl;
    return 0;
}