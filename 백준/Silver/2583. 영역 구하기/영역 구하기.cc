#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 1,0,0 };
int dy[4] = { 0,0,-1,1 };

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs(vector <vector<int>>& v1, vector <vector<int>>& visit, int i, int j) {
	queue <pair<int, int>> q;
	pair<int, int> tmp;
	visit[i][j] = 1;
	q.push({ i, j });

	int cnt = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (visit[nX][nY] == 0 && v1[nX][nY] == 0) {
					q.push({ nX, nY });
					visit[nX][nY] = 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, l; cin >> n >> m >> l;

	vector <int> v2(m, 0);
	vector <vector <int>> v1(n, v2);
	vector <vector <int>> visit(v1);

	for (int i = 0; i < l; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (int k = y1; k < y2; k++) {
			for (int j = x1; j < x2; j++) {
				v1[k][j] = 1;
			}
		}
	}

	int ans = 0;

	vector <int> vec;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && v1[i][j] == 0) {
				ans++;
				vec.push_back(bfs(v1, visit, i, j));
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << ans << endl;

	for (auto z : vec) {
		cout << z << " ";
	}

}