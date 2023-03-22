#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n,a,d; cin >> n >> a >> d;

	vector <int> cv(n);

	for (int i = 0; i < n; i++) {
		cin >> cv[i];
	}

	auto iter = find(cv.begin(), cv.end(), a);

	int now = a;
	int cnt = 0;

	if (iter != cv.end()) {
		cnt++;
	}

	for (auto i = iter; i != cv.end(); i++) {
		if (now + d == *i) {
			now += d;
			cnt++;
		}
	}

	cout << cnt;
}