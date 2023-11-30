#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;

	vector <int> weight(n + 1, 0);
	vector <int> value(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		weight[i] = a;
		value[i] = b;
	}

	int ans = 0;

	vector <vector <int>> table(n+1, vector <int>(x+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			// 현재 물건이 j kg 이하일 때만 실행
			table[i][j] = table[i - 1][j];
			if (j >= weight[i]) {
				table[i][j] = max(table[i - 1][j], table[i - 1][j - weight[i]] + value[i]);
				ans = ans > table[i][j] ? ans : table[i][j];
			}
		}
	}
	cout << ans;

}