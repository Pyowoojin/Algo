#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void dfs(vector <int>& vc, bool visited[]) {
	if (ans.size() == vc.size()) {
		for (int k = 0; k < ans.size(); k++) {
			cout << ans[k] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < vc.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			ans.push_back(vc[i]);
			dfs(vc, visited);
			ans.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	int n; cin >> n;

	vector <int> vc(n);
	bool* visited = new bool[n];
	fill(visited, visited + n, false);
	for (int i = 1; i <= n; i++) {
		vc[i-1] = i;
	}

	dfs(vc, visited);
}