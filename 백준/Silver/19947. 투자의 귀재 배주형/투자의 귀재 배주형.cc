#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, y; cin >> h >> y;
	int* dp = new int[y + 1];
	dp[0] = h;

	for (int i = 1; i <= y; i++) {
		if (i % 1 == 0) {
			dp[i] = dp[i - 1] * 0.05 + dp[i - 1];
		}
		
		if (i % 3 >= 0) {
			dp[i] = max(int(dp[i - 3] * 0.2 + dp[i - 3]), dp[i]);
		}

		if (i % 5 >= 0)
		{
			dp[i] = max(int(dp[i - 5] * 0.35 + dp[i - 5]), dp[i]);
		}
	}

	cout << dp[y];
}