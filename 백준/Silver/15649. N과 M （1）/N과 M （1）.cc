#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> vc;

void prt(vector <int>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << '\n';
}

void dfs(int k, int visited[]) {
	if (vc.size() == m) {
		prt(vc);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		vc.push_back(i + 1);
		dfs(i + 1, visited);
		vc.pop_back();
		visited[i] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int* visited = new int[n];
	fill(visited, visited + n, 0);
	dfs(0, visited);
}