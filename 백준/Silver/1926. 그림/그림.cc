#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int bfs(vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j) {
	int nowCnt = 1;
	queue<pair<int, int>> q;
	pair<int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;
		for (int k = 0; k < 4; k++) {
			int nX = dx[k] + x;
			int nY = dy[k] + y;

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (visit[nX][nY] != 1 && v1[nX][nY] == 1) {
					nowCnt++;
					q.push({ nX, nY });
					visit[nX][nY] = 1;
				}
			}
		}
	}

	return nowCnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector <int> vc2(m, 0);
	vector <vector<int>> vc1(n, vc2);
	vector <vector<int>> visit(vc1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c; cin >> c;
			vc1[i][j] = c;
		}
	}

	int cnt = 0;
	int maxN = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && vc1[i][j] == 1) {
				cnt++;
				int z = bfs(vc1, visit, i, j);
				maxN = max(z, maxN);
			}
		}
	}

	// prt(vc1);
	
	cout << cnt << endl << maxN;
}