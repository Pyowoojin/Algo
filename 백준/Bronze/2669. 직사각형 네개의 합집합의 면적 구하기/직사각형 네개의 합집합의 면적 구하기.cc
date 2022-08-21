#include <bits/stdc++.h>
using namespace std;

void prt(const vector <vector<int>>& square) {
	cout << endl;
	for (int i = 0; i < square.size(); i++) {
		for (int j = 0; j < square[0].size(); j++) {
			cout << square[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector <int> a(100, 0);
	vector <vector<int>> square(100, a);

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				square[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (square[i][j] == 1)
				cnt++;
		}
	}

	cout << cnt;
}