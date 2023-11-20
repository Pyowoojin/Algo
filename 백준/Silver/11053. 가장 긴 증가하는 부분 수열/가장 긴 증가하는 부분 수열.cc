#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 1;
	vector <int> vc;
	vector <int> dp(n);
	
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (vc[i] > vc[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(dp[i], ans);
			}
		}
	}

	cout << ans;


}