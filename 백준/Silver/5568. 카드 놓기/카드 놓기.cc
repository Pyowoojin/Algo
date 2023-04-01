#include <bits/stdc++.h>
using namespace std;

set <string> st;
vector <string> ans;

void dfs(vector <string>& vc, int maxN, bool visited[]) {
	if (ans.size() == maxN) {
		string s;
		for (int i = 0; i < ans.size(); i++) {
			s += ans[i];
		}
		st.insert(s);
		return;
	}

	for (int k = 0; k < vc.size(); k++) {
		if (visited[k] == false) {
			visited[k] = true;
			ans.push_back(vc[k]);
			dfs(vc, maxN, visited);
			ans.pop_back();
			visited[k] = false;
		}
	}
}

int main() {
	int n, r; cin >> n >> r;

	vector <string> vc;
	bool* visited = new bool[n];
	fill(visited, visited + n, false);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		vc.push_back(s);
	}

	dfs(vc, r, visited);

	cout << st.size();
}