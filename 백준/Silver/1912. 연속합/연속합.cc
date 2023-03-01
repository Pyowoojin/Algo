#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (i < 1)
			dp[i] = c;
		else {
			dp[i] = max(dp[i - 1] + c, c);
		}
	}

	int maxN = -10001;

	for (int i = 0; i < n; i++) {
		if (maxN < dp[i])
			maxN = dp[i];
	}
	cout << maxN;
}