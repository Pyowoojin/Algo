#include <bits/stdc++.h>
using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };


void prt(vector<vector<char>>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		vector<char> v2(m, '0');
		vector<vector<char>> v1(n, v2);
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int k = 0; k < s.length(); k++) {
				v1[i][k] = s[k];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				if (v1[i][j] == '.') {
					int nowX = i;
					int nowY = j;
					for (int k = 0; k < 8; k++) {
						int nextX = nowX + dx[k];
						int nextY = nowY + dy[k];
						if (nextX > -1 && nextY > -1 && nextX < v1.size() && nextY < v1[0].size()) {
							if (v1[nextX][nextY] == '*')
								cnt++;
						}
					}
					v1[i][j] = char(cnt + 48);
				}
			}
		}

		prt(v1);


		v1.clear();
		v2.clear();
	}
}