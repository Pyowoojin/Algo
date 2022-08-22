#include <bits/stdc++.h>
using namespace std;

/*void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (check[next] == 0)
			dfs(next, graph, check);
	}
}*/

void dfs(int start, vector<int> graph[], bool visit[]) {
	stack <int> s;
	s.push(start);
	visit[start] = 1;

	while (!s.empty()) {
		int now = s.top(); s.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (visit[next] == 0) {
				visit[next] = 1;
				s.push(now);
				s.push(next);
				break;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertex, edge; cin >> vertex >> edge;

	vector <int>* graph = new vector <int>[vertex + 1];

	bool* visit = new bool[vertex + 1];

	fill(visit, visit + vertex + 1, 0);

	for (int i = 0; i < edge; i++) {
		int f, t; cin >> f >> t;
		graph[f].push_back(t);
		graph[t].push_back(f);
	}

	int cnt = 0;
	for (int i = 1; i <= vertex; i++) {
		if (visit[i] == 0) {
			cnt++;
			dfs(i, graph, visit);
		}
	}
	cout << cnt << endl;

}