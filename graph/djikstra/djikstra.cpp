#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii> > vvii;

vector<int> dijkstra(vector<vector<ii> > &graph, int src, vi &prev){
	vector<int> dist (graph.size(), INF);
	dist[src] = 0;
	priority_queue<ii> toVisit;
	toVisit.push(make_pair(0, src));
	while(!toVisit.empty()){
		ii front = toVisit.top(); toVisit.pop();
		int d = front.first, u = front.second;

		if(d > dist[u]) continue;

		for(ii v : graph[u] ){
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				prev[v.first] = u;
				toVisit.push(ii(dist[v.first], v.first));
			}
		}

	}
	return dist;
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
	vi dv = dijkstra(graph, 0, prev);

	for(int i = 0; i < n; i++){
		cout << i << " dist:" << dv[i] << " | prev:" << prev[i] << endl;
	}

}