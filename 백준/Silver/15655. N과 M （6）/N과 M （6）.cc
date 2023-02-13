#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void dfs(int k, int maxN, vector <int>& num, vector <int>& visited, int nowNum) {
	if (k == maxN) {
		for (auto i : ans)
			cout << i << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		if (num[i] > nowNum) {
			ans.push_back(num[i]);
			dfs(k + 1, maxN, num, visited, num[i]);
			ans.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector <int> num;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		num.push_back(c);
	}

	sort(num.begin(), num.end());
	vector <int> visited(n);

	dfs(0, m, num, visited, 0);
}