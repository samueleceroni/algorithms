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

vector<edge> prim(const vvii &graph){
	vector<edge> sol;
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	vector<int> visited(graph.size(), 0);
	int mst_w = 0;
	int cont = 0;
	int currNode = 0;
	while(cont < graph.size() - 1){
		
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
	vector<edge> primv = prim(graph);
	cout << "----------\n";
	for(auto x : primv){
		cout << x.from << " " << x.to << " " << x.weight << '\n';
	}

}
/*

6 9
0 1 7
0 2 9
0 5 14
1 2 10
1 3 15
2 5 2
2 3 11
3 4 6
4 5 9

*/