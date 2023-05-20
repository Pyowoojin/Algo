#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int init = 0;
	int cnt = 1;
	cin >> init;
	for (int i = 1; i < n; i++) {
		int c; cin >> c;
		if (c >= init) {
			cnt++;
		}
		init = c;
	}

	cout << cnt;
}