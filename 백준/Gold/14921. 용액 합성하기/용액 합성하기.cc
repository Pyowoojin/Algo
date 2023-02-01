#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;

	vector <ll> vc;

	ll closedToZERO = 200000000;

	for (int i = 0; i < n; i++) {
		ll c; cin >> c;
		vc.push_back(c);
	}

	int start = 0; int end = vc.size() - 1;

	int answerA = vc[start], answerB = vc[end];

	while (start < end) {
		if (closedToZERO == 0) {
			answerA = 0, answerB = 0;
			break;
		}

		if (closedToZERO > abs(vc[start] + vc[end])) {
			closedToZERO = abs(vc[start] + vc[end]);
			answerA = vc[start], answerB = vc[end];
		}

		if (0 < vc[start] + vc[end]) {
			end--;
		}
		else {
			start++;
		}
	}

	cout << answerA + answerB;


	return 0;
}