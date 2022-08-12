#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(vector<vector <int>>& arr, vector<vector <int>>& visit, int i, int j) {
	queue<pair<int, int>> q;
	pair<int, int> tmp;

	q.push({ i,j });
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;
		
		for (int i = 0; i < 4; i++) {
			int dirx = x + dx[i];
			int diry = y + dy[i];

			if (dirx < 0 || dirx >= arr.size() || diry < 0 || diry >= arr[0].size())
				continue;
			if (arr[dirx][diry] == 1 && visit[dirx][diry] != 1) {
				visit[dirx][diry] = 1;
				q.push({ dirx,diry });
			}
		}

	}
}

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> ans;

	int cnt; cin >> cnt;

	while (cnt) {
		int n, m; cin >> n >> m;

		vector <int> v2(m, 0);
		vector<vector<int>> v1(n, v2);
		vector<vector<int>> visited(v1);

		int z; cin >> z;

		for (int i = 0; i < z; i++) {
			int x, y; cin >> x >> y;
			v1[x][y] = 1;
		}

		// print(v1);

		int worm = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v1[i][j] == 1 && visited[i][j] != 1) {
					worm++;
					visited[i][j] = 1;
					bfs(v1, visited, i, j);
				}
			}
		}
		ans.push_back(worm);
		v1.clear();
		visited.clear();
		cnt--;
	}

	for (auto p : ans)
		cout << p << '\n';

}