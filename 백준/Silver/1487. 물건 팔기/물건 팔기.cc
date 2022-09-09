#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	// 최대금액, 배송비
	vector <pair<int, int>> vc;

	for (int i = 0; i < n; i++) {
		int price, delivery; cin >> price >> delivery;
		vc.push_back({ price, -delivery });
	}

	int cnt = 0, ans = 0;
	int total = 0;
	int maxN = -9999999999;

	sort(vc.begin(), vc.end());

	while (cnt <= vc[vc.size() - 1].first) {
		total = 0;
		for (int i = 0; i < vc.size(); i++) {
			if (cnt <= vc[i].first) {
				if(cnt + vc[i].second > 0)
					total += vc[i].second + cnt;
			}
		}
		if (total > maxN) {
			maxN = total;
			ans = cnt;
		}
		cnt++;
	}
	if (maxN < 0)
		cout << "0";
	else
		cout << ans;

}