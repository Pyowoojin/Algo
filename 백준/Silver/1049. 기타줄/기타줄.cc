#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	vector <pair <int, int>> vc(m);

	for (int i = 0; i < m; i++) {
		cin >> vc[i].first >> vc[i].second;
	}

	int current = 0;
	int cost = 0;
	
	while (current < n) {
		if (n - current >= 6) {
			int minCost = 0x7fffffff;
			// 6개를 살거임
			for (int i = 0; i < vc.size(); i++) {
				if (minCost > min(vc[i].first, vc[i].second * 6))
					minCost = min(vc[i].first, vc[i].second * 6);
			}
			cost += minCost;
			current += 6;
		}

		else{
			int minCost = 0x7fffffff;

			for (int i = 0; i < vc.size(); i++) {
				if (minCost > min(vc[i].first, (n - current) * vc[i].second)) {
					minCost = min(vc[i].first, (n - current) * vc[i].second);
				}
			}
			cost += minCost;
			current += 6;
		}
	}

	cout << cost;
}