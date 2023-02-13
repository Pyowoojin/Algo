#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void dfs(int maxN, int k, vector <int> &arr, vector <int> &num, int nowNum, vector <int> &visited) {
	if (k == maxN) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < num.size(); i++) {
		if (nowNum <= num[i]) {
			ans.push_back(num[i]);
			dfs(maxN, k + 1, arr, num, i + 1, visited);
			ans.pop_back();
		}
	}
}

int main() {
	int n, m; cin >> n >> m;

	vector <int> arr(m);
	vector <int> num(n);
	vector <int> visited(n);

	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
	}
	dfs(m, 0, arr, num, 0, visited);

}