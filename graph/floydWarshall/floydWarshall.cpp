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
typedef vector<vector<int> > vvi;

vvi floydWarshall(const vvi &graph, vvi &prev){
	vvi dist(graph);
	int n = graph.size();
	for(int h = 0; h < n; h++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][j] > dist[i][h] + dist [h][j]){
					dist[i][j] = dist[i][h] + dist [h][j];
					prev[i][j] = prev[h][j];
				}
			}
		}
	}

	return dist;
}

int main(){
	int n, e;
	cin >> n >> e;
	vvi graph(n, vi(n, INF));
	int from, to, weight;
	for(int i = 0; i < e; i++){
		cin >> from >> to >> weight;
		graph[from][to] = weight;
		graph[to][from] = weight;
	}
	for(int i = 0; i < n; i++) graph[i][i] = 0;

	vvi prev(n);
	for(int i = 0; i<n; i++) prev[i] = vi(n, i);
	vvi fw = floydWarshall(graph, prev);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << fw[i][j] << "|" << prev[i][j] << "\t";
		}
		cout << endl;
	}
}