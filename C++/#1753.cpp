#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dis[20001];
const int INF = 2147483647;
vector<pair<int, int> > adj[20001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}
	fill(dis, dis + V + 1, INF);

	dis[K] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(dis[K], K));
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		int dist = cur.first;
		int idx = cur.second;
		if (dis[idx] != dist)
			continue;
		for (int i = 0; i < adj[idx].size(); i++) {
			pair<int, int> next = adj[idx][i];
			int cost = next.first;
			int nidx = next.second;
			if (dis[nidx] > dist + cost) {
				dis[nidx] = dist + cost;
				pq.push(make_pair(dis[nidx], nidx));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF)
			cout << "INF\n";
		else
			cout << dis[i] << "\n";
	}

	return 0;
}