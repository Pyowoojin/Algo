#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <int> ls;
	int n; cin >> n;
	int* dp = new int[n + 1];
	ls.push_back(0);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		ls.push_back(t);
	}
	dp[1] = ls[1];
	dp[2] = ls[1] + ls[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(ls[i] + dp[i - 3] + ls[i - 1], ls[i] + dp[i - 2]);
	}
	cout << dp[n];

}