#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };

void print(const vector<vector<char>>& v1)
{
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
	cout << endl;

}

void bfs(const vector<vector<char>>& v1, vector<vector<char>>& visit, int i, int j) {
	visit[i][j] = '1';
	queue <pair<int, int>> q;
	pair<int, int> tmp;

	q.push({ i,j });
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int dirx = x + dx[i];
			int diry = y + dy[i];
			if (dirx > -1 && dirx < v1.size() && diry > -1 && diry < v1[0].size()) {
				if (visit[dirx][diry] == '0' && v1[dirx][diry] == '#') {
					visit[dirx][diry] = '1';
					q.push({ dirx, diry });
				}
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	while (tc) {
		int n, m; cin >> n >> m;
		vector <char> v2(m, '0');
		vector<vector<char>> v1(n, v2);
		vector<vector<char>> visited(v1);

		// 입력부
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				v1[i][j] = c;
			}
		}

		int sheep = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == '0' && v1[i][j] == '#') {
					sheep++;
					bfs(v1, visited, i, j);
				}
			}
		}

		tc--;
		cout << sheep << endl;
	}

}