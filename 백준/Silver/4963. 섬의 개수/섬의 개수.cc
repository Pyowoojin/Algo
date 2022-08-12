#include <bits/stdc++.h>
using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void print(vector<vector <int>>& arr) {
	cout << endl;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs(vector<vector<int>>& a, vector<vector<int>>& visited, int i, int j) {
	queue<pair<int, int>> q;
	pair<int, int> now;
	q.push({ i,j });
	while (!q.empty()) {
		now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		visited[x][y] = 1;

		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX > -1 && nextX < a.size() && nextY > -1 && nextY < a[0].size()) {
				if (visited[nextX][nextY] != 1 && a[nextX][nextY] == 1) {
					q.push({ nextX, nextY });
					visited[nextX][nextY] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int n, m; cin >> m >> n;
		if (n == 0 && 0 == m)
			break;
		vector <int> v2(m, 0);
		vector<vector<int>> v1(n, v2);
		vector<vector<int>> visited(v1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int t; cin >> t;
				v1[i][j] = t;
			}
		}

		// print(v1);

		int land = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] != 1 && v1[i][j] == 1) {
					land++;
					bfs(v1, visited, i, j);
				}
			}
		}

		cout << land << endl;
		v1.clear(); visited.clear(); v2.clear();
	}
}