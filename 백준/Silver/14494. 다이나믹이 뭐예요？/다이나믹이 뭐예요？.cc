#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector <long long> v1(m+1, 0);
	vector <vector <long long>> v2(n+1, v1);
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < m+1; j++) {
			v2[i][j] = 1;
		}
	}

	for (int j = 0; j < 1; j++) {
		for (int i = 0; i < n+1; i++) {
			v2[i][j] = 1;
		}
	}

	v2[1][1] = 3;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			// 현재 배열은 나의 위 + 왼쪽위 + 왼쪽 배열들 경우의 수의 합
			v2[i][j] = (v2[i - 1][j] + v2[i - 1][j - 1] + v2[i][j - 1]) % 1000000007;
		}
	}

	cout << v2[n - 1][m - 1];

}