#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void prt(vector<vector<int>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

void bfs(vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j) {
	queue<pair<int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });


	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];
			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (v1[nX][nY] != 1 && visit[nX][nY] == 0) {
					q.push({ nX, nY });
					v1[nX][nY] = 5;
					visit[nX][nY] = 1;

				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> v2(m, 0);
	vector <vector<int>> v1(n, v2);
	vector <vector<int>> visit(v1);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v1[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && v1[i][j] != 1) {
				visit[i][j] = 1;
				bfs(v1, visit, i, j);
			}
		}
	}

	string ans = "NO";

	for (int i = n - 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v1[i][j] == 5)
				ans = "YES";
		}
	}

	cout << ans;

}