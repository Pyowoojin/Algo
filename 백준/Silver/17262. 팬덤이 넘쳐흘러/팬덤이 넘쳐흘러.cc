#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector <pair <int, int>> vc;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		vc.push_back({ b,a });
	}

	sort(vc.begin(), vc.end());

	int end = vc[0].first;
	int waiting = 0;

	for (int i = 1; i < vc.size(); i++) {
		// 누군가를 기다려야 함
		if (end < vc[i].second) {
			waiting += vc[i].second - end;
			end = vc[i].second;
		}
	}
	cout << waiting;
}