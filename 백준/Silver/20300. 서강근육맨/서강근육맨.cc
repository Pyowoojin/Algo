#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <unsigned long long> vc;

	for (int i = 0; i < n; i++) {
		unsigned long long c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end());

	unsigned long long maxN = 0;
	if (n % 2 == 0) {
		for (int k = 0, l = n-1; k < n / 2; k++, l--) {
			maxN = max(vc[k] + vc[l], maxN);
		}
		cout << maxN;
	}
	else {
		for (int i = 0, l = n - 2; i < n - 1; i++, l--) {
			maxN = max(vc[i] + vc[l], maxN);
		}
		maxN = max(maxN, vc[vc.size() - 1]);
		cout << maxN;
	}

}