#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void prt(vector<vector<int>>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++)
			cout << v1[i][j] << " ";
		cout << endl;
	}
}

void bfs(vector<vector<int>>& map, vector<vector<int>>& visit, int i, int j) {
	queue <pair <int, int>> q;
	pair <int, int> tmp;
	visit[i][j] = 0;
	int cnt = 1;
	q.push({ i, j });
	map[i][j] = 0;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (nY > -1 && nX > -1 && nX < map.size() && nY < map[0].size()) {
				if (visit[nX][nY] == 0 && map[nX][nY] == -1) {
					visit[nX][nY] = 1;
					map[nX][nY] = map[x][y] + 1;
					q.push({ nX, nY });
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
	vector<vector<int>> v1(n, v2);
	vector<vector<int>> visit(v1);

	pair<int, int> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c; cin >> c;

			if (c == 1) {
				v1[i][j] = -1;
				continue;
			}
			else if (c == 2) {
				start = { i,j };
			}
			v1[i][j] = c;

		}
	}
	
	bfs(v1, visit, start.first, start.second);

	prt(v1);

}