#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef unordered_set<int> usi;
typedef vector<int> vi;
typedef vector<vector<ii> > vvii;

typedef struct edge{
	int from, to, weight;

	bool operator>(struct edge other) const {
		return tie(weight, from, to) > tie(other.weight, other.from, other.to);
	}
}edge;

vector<int> prim(const vvii &graph){
	vector<edge> sol;
	priority_queue<edge> pq;
	vector<int> visited(n, 0);
	int mst_w = 0;
	int cont = 0;
	int currNode = 0;
	while(cont < graph.size()){
		
		visited[currNode] = 1;

		for(ii e: graph[currNode]){
			if(!visited[e.first]){
				pq.push({currNode, e.first, e.second});
			}
		}

		edge nextEdge = {-1, currNode, -1};
		while(!pq.empty() && visited[nextEdge.to]){
			nextEdge = pq.top();
			pq.pop();
		}
		
		assert(nextEdge.to != currNode);
		
		cont++;
		mst_w += nextEdge.weight;
		currNode = nextEdge.to;
		sol.push_back(nextEdge);

	}
	return sol;
}

int main(){
	int n, e;
	cin >> n >> e;
	vvii graph(n);
	int from, to, weight;
	for(int i = 0; i < e; i++){
		cin >> from >> to >> weight;
		graph[from].push_back(make_pair(to, weight));
		graph[to].push_back(make_pair(from, weight));
	}
	vi prev(n, -1);
	vi spfav = spfa(graph, 0, prev);

	for(int i = 0; i < n; i++){
		cout << i << " dist:" << spfav[i] << " | prev:" << prev[i] << endl;
	}

}