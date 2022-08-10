#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	int u, l, r, d; cin >> u >> l >> r >> d;
	vector <string> str1;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		str1.push_back(s);
	}

	vector <char> v2(m + r + l, '0'); // 열의 개수
	vector <vector<char>> v1(n + d + u, v2); // 행의 개수

	// 행은 짝수면 # 시작, 홀수면 . 시작

	bool start = 1;
	// 윗부분 구현
	for (int i = 0; i < u; i++) {
		if (i % 2 == 0)
			start = 1;
		else
			start = 0;
		for (int j = 0; j < m + r + l; j++) {
			if (start == 1) {
				cout << "#";
				start = 0;
			}
			else {
				cout << ".";
				start = 1;
			}
		}
		cout << '\n';
	}

	// 좌와 우 구현
	for (int i = u; i < n + u; i++) {
		if (i % 2 == 0)
			start = 1;
		else
			start = 0;
		// 좌측 출력
		for (int j = 0; j < l; j++) {
			if (start == 1) {
				cout << "#";
				start = 0;
			}
			else {
				cout << ".";
				start = 1;
			}
		}
		// 글자 출력
		cout << str1[i - u];
		if (m % 2 == 1)
			start = !start;
		// 우측 출력
		for (int k = 0; k < r; k++) {
			if (start == 1) {
				cout << "#";
				start = 0;
			}
			else {
				cout << ".";
				start = 1;
			}
		}
		cout << '\n';
	}

	// 하단 구현
	for (int i = u + n; i < u + n + d; i++) {
		if (i % 2 == 0)
			start = 1;
		else
			start = 0;
		for (int j = 0; j < r + l + m; j++) {
			if (start == 1) {
				cout << "#";
				start = 0;
			}
			else {
				cout << ".";
				start = 1;
			}
		}
		cout << '\n';
	}

	


}