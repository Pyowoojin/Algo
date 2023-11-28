#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int order = 1;

void dfs(vector <vector <int>>& vc, int loc) {
	visited[loc] = order;
	order++;

	for (int i = 0; i < vc[loc].size(); i++) {
		if (visited[vc[loc][i]] == 0)
		{
			dfs(vc, vc[loc][i]);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, r; cin >> n >> m >> r;
	vector <vector <int>> vc(n+1);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(vc[i].begin(), vc[i].end());
	}

	dfs(vc, r);

	for (int i = 1; i <=n; i++) {
		cout << visited[i] << '\n';
	}
}