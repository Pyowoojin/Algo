#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nul; cin >> nul;
	while (nul) {
		char cs = cin.get();
		cin.ignore();
		int n, m; cin >> n >> m;
		vector <char> v2(m, 0);
		vector < vector<char>> v1(n, v2);

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int k = 0; k < s.length(); k++) {
				v1[i][k] = s[k];
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j < m - 2) {
					if (v1[i][j] == '>') {
						if (v1[i][j + 1] == 'o') {
							if (v1[i][j + 2] == '<') {
								cnt++;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i < n - 2) {
					if (v1[i][j] == 'v') {
						if (v1[i + 1][j] == 'o') {
							if (v1[i + 2][j] == '^') {
								cnt++;
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
		v2.clear();
		v1.clear();
		nul--;
	}
}