#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector <vector <pair <int, int>>>& graph, int start, vector <int> & dist) {
	dist[start] = 0;
	priority_queue <pair <int, int>> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next] > nCost + cost) {
				dist[next] = cost + nCost;
				pq.push({ -dist[next], next });
				continue;
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector < vector <pair <int, int>>> graph(n);
	vector <int> dist(n);
	fill(dist.begin(), dist.end(), 0x7fffffff);

	for (int i = 0; i < m; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		graph[from-1].push_back({ to-1, cost });
		graph[to-1].push_back({ from -1 ,cost });
	}

	int start = 1, end = n - 1;

	dijkstra(graph, start-1, dist);

	cout << dist[end];
}