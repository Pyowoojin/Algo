#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, s, m; cin >> n >> s >> m;

	vector <int> list;
	vector <bool> dp2(m+1, false);
	vector <vector <bool>> dp(n + 1, dp2);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		list.push_back(c);
	}

	// 초기화
	if (list[0] + s <= m) {
		dp[0][s + list[0]] = true;
	}
	if (s - list[0] >= 0) {
		dp[0][s - list[0]] = true;
	}

	for (int i = 1; i < list.size(); i++) {
		for (int k = 0; k <= m; k++) {
			if (dp[i - 1][k] == true)
			{
				if (k + list[i] <= m)
					dp[i][list[i] + k] = true;
				if (k - list[i] >= 0)
					dp[i][k - list[i]] = true;
			}
		}
	}

	int maxN = -1;
	
	for (int i = 0; i <= m; i++) {
		if (maxN < i && dp[n - 1][i] == true)
			maxN = i;
	}


	cout << maxN;

}