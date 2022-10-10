#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000;
const int N = 100000;


int main() {
	int n,m; cin >> n >> m;
	vector<pair<int, pair<int,int>>> edges;
	for(int i = 1; i <= m; i++){
		int u,v,wt;
		cin >> u >> v >> wt;
		edges.push_back({wt,{u,v}});
	}
	int distance[n+1];
	distance[1] = 0;
	for(int i = 2; i<=n; i++){
		distance[i] = INF;
	}

	for(int i = 1; i<=(n-1); i++){
		for(auto &edge: edges){
			int u,v,w;
			w = edge.first;
			u = edge.second.first;
			v = edge.second.second;
			if(distance[u] + w <= distance[v]){
				distance[v] = distance[u] + w;
			}
		}
	}

	for(int i = 1; i <=n; i++){
		cout << distance[i] << " ";
	}


}