#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int tc; cin >> tc;

	while (tc--) {
		int n; cin >> n;
		vector <pair <int, int>> vc(n);
		for (int i = 0; i < n; i++) {
			cin >> vc[i].first;
			cin >> vc[i].second;
		}
		sort(vc.begin(), vc.end());
		int ans = 1;
		int ptr = 0;

		for (int i = 1; i < n; i++) {
			// 밑의 애는 위의 애의 second보다 커야함
			if (vc[ptr].second > vc[i].second) {
				ans++;
				ptr = i;
			}
		}

		cout << ans << '\n';
	}
}