#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector <int> vc(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}
	sort(vc.begin(), vc.end());

	int start = 0, end = n - 1;
	int ans = 0;
	while (start < end) {
		int sum = vc[start] + vc[end];
		if (sum <= k) {
			ans++;
			start++; end--;
			continue;
		}

		if (sum > k) {
			end--;
		}
	}

	cout << ans;
}