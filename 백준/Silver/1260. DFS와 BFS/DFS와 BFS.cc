#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> graph[], bool visit[]) {
	queue <int> q;
	visit[start] = 1;
	q.push(start);
	cout << start << " ";

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (visit[next] == 0) {
				cout << next << " ";
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}

void dfs(int start, vector<int> graph[], bool visit[]) {
	stack <int> s;
	visit[start] = 1;
	s.push(start);
	cout << start << " ";

	while (!s.empty()) {
		int now = s.top(); s.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (visit[next] == 0) {
				cout << next << " ";
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

	int vertex, edge, start; cin >> vertex >> edge >> start;

	vector<int>* graph = new vector<int>[vertex + 1];
	bool* visit = new bool[vertex + 1];
	fill(visit, visit + vertex + 1, 0);

	for (int i = 0; i < edge; i++) {
		int from, to; cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <=vertex; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start, graph, visit);
	
	fill(visit, visit + vertex + 1, 0);
	cout << endl;

	bfs(start, graph, visit);

}