#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int dp[501][501];

int main() {
	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	ans = dp[0][0];

	for (int i = 1, j = 1; i < n; i++, j++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			ans = max(dp[i][j], ans);
		}
	}

	cout << ans;
}