#include <bits/stdc++.h>
using namespace std;

void Backtracking(vector <int> &list, vector <int> &ans, int cnt, int maxX, int nowI) {
	if (cnt == maxX) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < list.size(); i++) {
		if (i >= nowI) {
			ans.push_back(list[i]);
			Backtracking(list, ans, cnt + 1, maxX, list[i]);
			ans.pop_back();
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	vector <int> list;
	vector <int> ans;
	for (int i = 1; i <= n; i++) {
		list.push_back(i);
	}

	Backtracking(list, ans, 0, m, 0);

}