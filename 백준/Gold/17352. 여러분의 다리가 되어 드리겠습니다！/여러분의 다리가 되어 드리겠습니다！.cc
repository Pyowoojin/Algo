#include <bits/stdc++.h>
using namespace std;

int start = 0, end = 0;

void dfs(vector<int> graph[], int start, bool visit[]) {
	visit[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (visit[next] == 0) {
			dfs(graph, next, visit);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int island; cin >> island;

	vector <int>* graph = new vector<int>[island + 1];

	bool* visit = new bool[island + 1];

	fill(visit, visit + island + 1, 0);

	for (int i = 0; i < island - 2; i++) {
		int from, to; cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<int> ans;



	for (int i = 1; i < island + 1; i++) {
		if (visit[i] == 0) {
			ans.push_back(i);
			dfs(graph, i, visit);
		}
	}

	for (auto z : ans)
		cout << z << " ";


}