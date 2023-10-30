#include <bits/stdc++.h>
using namespace std;

int CalcArea(vector <vector <int>>& maps) {
	int cnt = 0;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[0].size(); j++) {
			if (maps[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	vector <vector <int>> maps(100, vector <int>(100, 1));

	int n; cin >> n;

	while (n--) {
		int x, y; cin >> x >> y;

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				maps[i][j] = 0;
			}
		}
	}

	cout << CalcArea(maps);
	
}