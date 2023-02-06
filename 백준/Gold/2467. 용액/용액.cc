#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;

	vector <ll> vc;

	int start = 0, end = n - 1;
	ll ansA = -1, ansB = -1;

	int minD = 2000000000;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	while (start < end) {
		if (minD > abs(vc[start] + vc[end])) {
			minD = abs(vc[start] + vc[end]);
			ansA = vc[start];
			ansB = vc[end];
		}

		if (vc[start] + vc[end] == 0) {
			ansA = vc[start];
			ansB = vc[end];
			break;
		}

		if (vc[start] + vc[end] > 0) {
			end -= 1;
		}

		if (vc[start] + vc[end] < 0){
			start += 1;
		}
	}

	cout << ansA << " " << ansB;

}