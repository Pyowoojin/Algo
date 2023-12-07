#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector <pair <int, int>> vc;
	int ans = 0;
	int nowTime = 0;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int arrive, timer; cin >> arrive >> timer;
		vc.push_back({ arrive, timer });
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < n; i++) {
		// 기다려야 함
		if (vc[i].first > nowTime) {
			nowTime = vc[i].first;
		}
		nowTime += vc[i].second;
	}

	cout << nowTime;

}