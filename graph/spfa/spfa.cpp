#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_set>

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef unordered_set<int> usi;
typedef vector<int> vi;
typedef vector<vector<ii> > vvii;

vector<int> spfa(vvii &graph, int src, vector<int> &prev){
	vector<int> dist (graph.size(), INF);
	dist[src] = 0;
	queue<int> toVisit;
	usi inToVisit;
	toVisit.push(src);
	inToVisit.insert(src);
	while(!toVisit.empty()){
		int u = toVisit.front(); toVisit.pop();
		inToVisit.erase(u);
		for(ii e : graph[u]){
			if(dist[e.first] > e.second + dist[u]){
				dist[e.first] = e.second + dist[u];
				prev[e.first] = u;
				if(!inToVisit.count(e.first)){
					toVisit.push(e.first);
					inToVisit.insert(e.first);
				}
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
	vi spfav = spfa(graph, 0, prev);

	for(int i = 0; i < n; i++){
		cout << i << " dist:" << spfav[i] << " | prev:" << prev[i] << endl;
	}

}