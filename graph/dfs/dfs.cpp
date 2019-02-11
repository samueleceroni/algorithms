#include<iostream>
#include<vector>
#include<stack>

//#define DIRECTIONED

using namespace std;

vector<int> dfs(vector<vector<int> > g){
	vector<int> result;
	vector<int> visited(g.size(), 0);
	stack<int> toVisit;
	int currNode = 0;
	toVisit.push(currNode);
	while(!toVisit.empty()){
		currNode = toVisit.top();
		toVisit.pop();
		if(visited[currNode] == 1) continue;
		result.push_back(currNode);
		visited[currNode] = 1;
		for(int node : g[currNode]){
			if(visited[node] == 0){
				toVisit.push(node);
			}
		}
	}
	return result;
}


int main(){
	int n, e, from, to;
	cin >> n >> e;
	vector<vector<int> > g(n);
	for(int i=0; i<e; i++){
		cin >> from >> to;
		g[from].push_back(to);
		#ifndef DIRECTIONED
			g[to].push_back(from);
		#endif
	}
	vector<int> bfsv = dfs(g);
	
	for(auto x : bfsv){
		cout << x << ' ';
	}

	return 0;
}