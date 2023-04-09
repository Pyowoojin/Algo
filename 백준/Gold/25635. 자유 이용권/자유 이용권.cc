#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n; cin >> n;

	vector <long long> vec;
	long long maxN = -999;
	long long total = 0;

	for (long long i = 0; i < n; i++) {
		long long c; cin >> c;
		vec.push_back(c);
		maxN = max(maxN, c);
		total += c;
	}

	total = total - maxN;

	if (total >= maxN - 1) {
		cout << total + maxN;
	}
	else {
		long long tmpTotal = total;
		long long tmpMax = maxN;
		long long cnt = 0;
		long long i = 0;
		while (tmpTotal && tmpMax) {
			if (i % 2 == 0)
				tmpMax--;
			else
				tmpTotal--;
			cnt++;
			i++;
		}

		if (tmpTotal == 0 && tmpMax > 0) {
			cnt++;
		}
		cout << cnt;
	}

}