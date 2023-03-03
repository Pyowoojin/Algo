#include <bits/stdc++.h>
using namespace std;
using pii = pair <int, int>;

void dijkstra(vector <vector <pair <int, int>>>& vc, vector <int>& dist, int start) {
	dist[start - 1] = 0;

	priority_queue <pii, vector <pii>, greater<pii>> pq;
	pq.push({ 0, start-1 });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first; pq.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0; i < vc[cur].size(); i++) {
			int nextNode = vc[cur][i].first;
			int nextCost = vc[cur][i].second;

			if (dist[nextNode] > nextCost + cost) {
				dist[nextNode] = nextCost + cost;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}
}

int main() {
	int n, m, start; cin >> n >> m >> start;

	vector <vector <pair <int, int>>> vc(n);
	vector <int> dist(n, 0x7fffffff);

	for (int i = 0; i < m; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		vc[from - 1].push_back({ to - 1, cost });
	}

	dijkstra(vc, dist, start);

	for (int i = 0; i < n; i++) {
		if (dist[i] == 0x7fffffff)
			cout << "INF";
		else
			cout << dist[i];
		cout << '\n';
	}
}