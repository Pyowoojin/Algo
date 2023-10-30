#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	vector <int> ans(n, 0);
	stack <pair <int, int>> five;
	int vectorPointer = 0;

	for (int i = 0; i < n; i++) {
		int nowNum; cin >> nowNum;

		if (five.size() >= 1) {
			while (!five.empty() && nowNum > five.top().first) {
				ans[five.top().second] = nowNum;
				five.pop();
			}
		}
		five.push({nowNum, i});

	}

	while (!five.empty()) {
		ans[five.top().second] = -1;
		five.pop();
	}

	for (auto i : ans) {
		cout << i << " ";
	}

}