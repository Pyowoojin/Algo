#include <bits/stdc++.h>
using namespace std;

int visited[500];

int cnt;

void dfs(vector <vector <int>>& vc, int k, int depth) {
	if (!visited[k]) {
		visited[k] = true;
		cnt++;
	}
	
	if (depth == 2) {
		return;
	}

	for (int i = 0; i < vc[k].size(); i++) {
		dfs(vc, vc[k][i], depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	
	vector <vector <int>> vc(n + 1);
	visited[1] = true;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	for (int i = 0; i < vc[1].size(); i++) {
		dfs(vc, vc[1][i], 1);
	}
	cout << cnt;
}