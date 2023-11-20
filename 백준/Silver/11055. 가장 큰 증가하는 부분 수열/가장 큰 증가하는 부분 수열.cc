#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> vc;
	vector <int> dp(n);

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}
	int ans = vc[0];
	dp[0] = vc[0];

	for (int i = 1; i < n; i++) {
		dp[i] = vc[i];
		for (int j = 0; j < i; j++) {
			if (vc[i] > vc[j]) {
				dp[i] = max(dp[i], dp[j] + vc[i]);
				ans = max(dp[i], ans);
			}
		}
	}

	cout << ans;


}