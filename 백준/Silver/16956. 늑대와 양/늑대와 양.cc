#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void prt(vector<vector<char>>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++)
			cout << v1[i][j] << "";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	cin.ignore();
	vector<char> v2(m, '0');
	vector<vector<char>> v1(n, v2);


	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		for (int j = 0; j < s.length(); j++)
			v1[i][j] = s[j];
		cin.ignore();
	}

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v1[i][j] == 'S') {
				int nowX = i;
				int nowY = j;
				for (int k = 0; k < 4; k++) {
					int nX = nowX + dx[k];
					int nY = nowY + dy[k];

					if (nX > -1 && nY > -1 && nX < n && nY < m) {
						if (v1[nX][nY] == 'W') {
							flag = false;
							break;
						}
					}
				}
			}
			if (v1[i][j] == 'W') {
				int nowX = i;
				int nowY = j;
				for (int k = 0; k < 4; k++) {
					int nX = nowX + dx[k];
					int nY = nowY + dy[k];

					if (nX > -1 && nY > -1 && nX < n && nY < m) {
						if (v1[nX][nY] == '.') {
							v1[nX][nY] = 'D';
						}
					}
				}
			}
		}
	}

	cout << flag << endl;
	if(flag) prt(v1);

}