#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

template <typename T>
void prt2d(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int rainfall;

void bfs(vector <vector<int>>& v1, vector<vector <int>>& visit, int i, int j) {
	queue <pair<int, int>> q;
	pair<int, int> tmp;
	visit[i][j] = 1;
	q.push({ i,j });

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;
		for (int k = 0; k < 4; k++) {
			int nX = x + dx[k];
			int nY = y + dy[k];

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1.size()) {
				if (visit[nX][nY] == 0 && v1[nX][nY] != -1) {
					q.push({ nX,nY });
					visit[nX][nY] = 1;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector <int> vc2(n, 0);
	vector <vector<int>> vc1(n, vc2);
	vector <vector<int>> visit(vc1);

	int maxGround = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c; cin >> c;
			vc1[i][j] = c;
			maxGround = max(c, maxGround);
		}
	}
	vector <vector<int>> origin(vc1);

	int maxN = 0;

	for (int z = 0; z<= maxGround; z++) {
		int cnt = 0;

		vc1 = origin;
		// 침수시키기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vc1[i][j] <= rainfall) {
					vc1[i][j] = -1;
				}
			}
		}
		fill(visit.begin(), visit.end(), vector <int>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0 && vc1[i][j] != -1) {
					cnt++;
					bfs(vc1, visit, i, j);
				}
				maxN = max(cnt, maxN);
			}
		}

		// prt2d(vc1);

		// cout << maxN << endl;

		rainfall++;

	}

	cout << maxN;


}