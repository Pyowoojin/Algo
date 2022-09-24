#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt2d(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int maxCnt, ans;

void dfs(vector <int> graph[], bool visit[], int start) {
	if (maxCnt == 4) {
		ans = 1;
		return;
	}
	visit[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int now = graph[start][i];
		if (visit[now] != 1) {
			maxCnt++;
			dfs(graph, visit, now);
			visit[now] = 0;
			maxCnt--;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertex, edge; cin >> vertex >> edge;
	vector <int>* vc = new vector <int>[vertex];

	bool* visit = new bool[vertex];
	fill(visit, visit + vertex, 0);

	for (int i = 0; i < edge; i++) {
		int from, to; cin >> from >> to;
		vc[from].push_back(to);
		vc[to].push_back(from);
	}

	/*for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			cout << i << " -> " << vc[i][j] << endl;
		}
		cout << endl;

	}*/

	// dfs,,,, 깊이 우선 탐색 -> 재귀로 구현

	for (int i = 0; i < vertex; i++) {
		if (ans == 1)
			break;
		dfs(vc, visit, i);
		fill(visit, visit + vertex, 0);
	}

	cout << ans;

}