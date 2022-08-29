#include <bits/stdc++.h>
using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void bfs(vector<vector<int>>& v1, vector<vector<int>> &visit, vector<vector<int>>& dist) {
	queue <pair <int, int>> q;
	pair <int, int> tmp;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			if (v1[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}


	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int k = 0; k < 8; k++) {
			int nX = x + dx[k];
			int nY = y + dy[k];

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (v1[nX][nY] == 0 && visit[nX][nY] == 0) {
					q.push({ nX,nY });
					visit[nX][nY] = 1;
					dist[nX][nY] = dist[x][y] + 1;
				}
			}
		}

	}
}

void prt(const vector<vector<int>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
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
	vector<vector<int>> dist(v1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c; cin >> c;
			v1[i][j] = c;
			if (c == 1) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = -1;
			}
		}
	}

	bfs(v1, visit, dist);

	int maxn = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxn = max(dist[i][j], maxn);
		}
	}
	cout << maxn;
}