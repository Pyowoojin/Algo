#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long n, m; cin >> n >> m;
	vector <long long> vc;

	for (int i = 0; i < n; i++) {
		long long c; cin >> c;
		vc.push_back(c);
	}
	sort(vc.begin(), vc.end());
	
	int startPtr = 0;
	int endPtr = 0;

	long long nowDiff = 0;
	long long minDiff = 0x7fffffff;

	while (startPtr <= endPtr && endPtr < n) {
		if (vc[endPtr] - vc[startPtr] >= m) {
			nowDiff = vc[endPtr] - vc[startPtr];
			if (minDiff > nowDiff) {
				minDiff = nowDiff;
				startPtr++;
			}
			else if (minDiff < nowDiff)
				startPtr++;
			else
				endPtr++;
		}
		else {
			endPtr++;
		}
	}
	cout << minDiff;
}