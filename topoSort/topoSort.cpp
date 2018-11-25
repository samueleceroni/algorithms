#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

struct Node{
    int data; // could be whatever, also NULL
    vector<int> childs;
    int mark; // 0 not Visited, 1 temp, 2 perm
};

struct Graph{
    vector<Node> nodes;
};

bool visit(int currNode, Graph &g, list<int> &sol, unordered_set<int> &unmarked){
    if(g.nodes[currNode].mark == 2){return;}
    if(g.nodes[currNode].mark == 1){return false;} // not a DAG
    g.nodes[currNode].mark = 1;
    unmarked.erase(currNode);

    for(auto n : g.nodes[currNode].childs){
        visit(n, g, sol, unmarked);
    }
    g.nodes[currNode].mark = 2;
    sol.push_front(currNode);
    return true;
}

list<int> topoSort(Graph &g){
    unordered_set<int> unmarked;
    list<int> sol;
    for(int i=0; i<g.nodes.size(); i++){
        unmarked.insert(i);
    }
    while(!unmarked.empty()){
        int nextEl = *unmarked.begin();
        if(!visit(nextEl, g, sol, unmarked)){return list<int>();}
    }
    return sol;
}

int main(){
    Graph g;// = new Graph;
    int n = 5;
    for(int i = 0; i < n; i++){
        Node n;// = new Node;
        //n.data = i;
        n.mark = 0;
        g.nodes.push_back(n);
    }
    g.nodes[0].childs.push_back(1);
    g.nodes[0].childs.push_back(2);
    g.nodes[0].childs.push_back(3);
    g.nodes[1].childs.push_back(4);
    g.nodes[2].childs.push_back(4);
    g.nodes[3].childs.push_back(2);
    g.nodes[3].childs.push_back(4);
    
    list <int> t = topoSort(g);
    for(int i : t){
        cout << i << ' ';
    }
}