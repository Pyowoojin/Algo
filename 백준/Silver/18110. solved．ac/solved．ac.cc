#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque <int> dq;
	int n; cin >> n;
	if (n == 0)
		cout << "0";

	else {
		for (int i = 0; i < n; i++) {
			int c; cin >> c;
			dq.push_back(c);
		}
		float total = n;
		float fif = 0.15f;
		int res = round(n * fif);

		sort(dq.begin(), dq.end());

		for (int i = 0; i < res; i++) {
			dq.pop_front();
			dq.pop_back();
		}

		fif = accumulate(dq.begin(), dq.end(), 0);

		res = round(fif / dq.size());

		cout << res;


	}

}