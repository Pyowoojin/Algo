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

	long long n; cin >> n;
	
	vector <long long> vc;

	for (long long i = 0; i < n; i++) {
		long long c; cin >> c;
		vc.push_back(c);
	}

	long long m; cin >> m;

	sort(vc.begin(), vc.end());


	long long start = 0, end = vc[vc.size() - 1];
	long long ans = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		
		long long total = 0;

		for (long long i = 0; i < n; i++) {
			if (vc[i] >= mid)
				total += mid;
			else if (vc[i] < mid)
				total += vc[i];
		}

		if (total > m) {
			end = mid - 1;
		}
		else if (total <= m) {
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}

	}

	cout << ans;
}