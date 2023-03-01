#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	int* dp = new int[n + 1];
	fill(dp, dp + n + 1, 1);
	int* arr = new int[n + 1];
	
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr[i] = c + 1;
	}

	for (int i = n-2; i >= 0; i--) {
		if (arr[i] + i >= n) {
			continue;
		}
		else {
			dp[i] = dp[i + arr[i]] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
}