#include <bits/stdc++.h>
using namespace std;

int t;
int ans;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char chk[6][6];

void prt(vector <vector<char>>& vc) {
	for(int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int distance, int i, int j, vector <vector <char>> &vc) {
	if (i == 0 && j == vc[0].size() - 1) {
		if (distance == t) {
			ans++;
		}
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nX = dx[k] + i;
		int nY = dy[k] + j;
		if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
			if (!chk[nX][nY] && vc[nX][nY] == '.') {
				chk[nX][nY] = true;
				dfs(distance + 1, nX, nY, vc);
				chk[nX][nY] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m >> t;
	vector <char> vc2(m, '0');
	vector <vector <char>> vc(n, vc2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j];
		}
	}
	chk[n - 1][0] = true;
	dfs(1, n-1, 0, vc);
	cout << ans;
}