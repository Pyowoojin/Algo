#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> vc;
	vector <pair <int, vector<int>>> dp(n);

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	int ansmax = 0;
	int ans = 0;
	dp[0].first = 1;
	dp[0].second.push_back(vc[0]);

	for (int i = 1; i < n; i++) {
		dp[i].first = 1;
		for (int j = 0; j < i; j++) {
			// 
			if (vc[i] > vc[j]) {
				if (dp[j].first + 1 > dp[i].first) {
					dp[i].first = dp[j].first + 1;
					dp[i].second = dp[j].second;

					if (ansmax < dp[i].first) {
						ansmax = dp[i].first;
						ans = i;
					}
				}
			}
		}
		dp[i].second.push_back(vc[i]);
	}

	cout << dp[ans].second.size() << '\n';
	for (int i = 0; i < dp[ans].second.size(); i++) {
		cout << dp[ans].second[i] << " ";
	}

}