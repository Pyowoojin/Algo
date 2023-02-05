#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x; cin >> n >> x;

	vector <int> vc;

	int maxN = 0;
	int days = 0;
	// 슬라이딩 윈도우

	int tmpN = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);

		if (i < x) {
			tmpN += c;
		}
		else {
			tmpN -= vc[i - x];
			tmpN += c;
		}

		if (tmpN >= maxN) {
			if (tmpN > maxN)
				days = 1;
			else if (tmpN == maxN)
				days++;
			maxN = tmpN;
		}
	}

	if (maxN == 0)
		cout << "SAD";
	else {
		cout << maxN << '\n' << days;
	}

}