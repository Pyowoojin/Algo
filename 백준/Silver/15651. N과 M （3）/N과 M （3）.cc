#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void dfs(int maxN, int k, vector <int> &arr, vector <int> &num) {
	if (k == maxN) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		ans.push_back(num[i]);
		dfs(maxN, k+1, arr, num);
		ans.pop_back();
	}
}

int main() {
	int n, m; cin >> n >> m;

	vector <int> arr(m);
	vector <int> num(n);

	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
	}
	dfs(m, 0, arr, num);

}