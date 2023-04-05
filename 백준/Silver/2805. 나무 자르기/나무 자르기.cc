#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k; cin >> n >> k;

	vector <int> vc;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end());

	long long start = 0;
	long long end = vc[vc.size() - 1];

	int ans = 0;

	long long mid = (start + end) / 2;
	while (start <= end) {
		mid = (start + end) / 2;
		long long total = 0;
		
		// cout << start << " / " << end << " / " << mid << endl;
		 
		for (auto i : vc) {
			if (i > mid) {
				total += i - mid;
			}
		}
		if (total < k) {
			end = mid - 1;
		}
		else {
			ans = mid;
			start = mid + 1;
		}

	}

	cout << ans;
}