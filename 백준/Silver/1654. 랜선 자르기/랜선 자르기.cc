#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long k; cin >> k;
	long long n; cin >> n;

	vector <long long> vc;

	for (int i = 0; i < k; i++) {
		long long c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end());

	long long start = 0, end = vc[vc.size() - 1];
	long long ans = 0;

	while (start <= end) {
		long long cnt = 0;
		long long mid = (start + end) / 2;
		if (mid == 0)
			mid = 1;

		for (int i = 0; i < k; i++) {
			cnt += vc[i] / mid;
		}

		//cout << cnt << " : " << start << " mid : " << mid << "  " << end << endl;
		
		if (cnt < n) {
			end = mid - 1;
		}
		else if (cnt >= n) {
			if (ans < mid)
				ans = mid;
			start = mid+1;
		}
	}

	cout << ans;
}