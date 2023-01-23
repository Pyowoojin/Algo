#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int needToPeople, cityCount;
	cin >> needToPeople >> cityCount;

	int dp[10001];

	fill(dp, dp + 10001, 100001);

	vector < pair< int, int>> cities;

	for (int i = 0; i < cityCount; i++) {
		int cost, customers; cin >> cost >> customers;
		cities.push_back({ cost, customers });
	}

	for (int i = 1; i <= 10001; i++) {
		for (int j = 0; j < cityCount; j++) {
			if ((i % cities[j].second) == 0) {
				dp[i] = min(dp[i], ((i / cities[j].second) * cities[j].first));
			}
			if (i < cities[j].second) {
				dp[i] = min(dp[i], cities[j].first);
			}
			if (i - cities[j].second >= 0) {
				dp[i] = min({ dp[i], dp[i - cities[j].second] + cities[j].first });
			}

		}
	}

	/*for (int i = 1; i <= needToPeople; i++) {
		cout << i << " : " << dp[i] << '\n';
	}*/

	cout << dp[needToPeople];

}