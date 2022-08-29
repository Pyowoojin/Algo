#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

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

	vector<int> v2(n, 0);
	vector<vector<int>> v1(m, v2);
	vector<vector<int>> visit(v1);
	vector<vector<int>> dist(v1);

	queue <pair<int, int>> q;
	pair <int,int> tmp;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int c; cin >> c;
			v1[i][j] = c;
			if (c == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
			else if (c == -1){
				v1[i][j] -= 1;
			}
			else {
				dist[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if(nX > -1 && nY > -1 && nX <m && nY < n){
				if (v1[nX][nY] == 0 && visit[nX][nY] == 0) {
					visit[nX][nY] = 1;
					q.push({ nX,nY });
					dist[nX][nY] = dist[x][y] + 1;
				}
			}
		}
	}

	int maxN = -999;

	// prt(dist);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == -1) {
				maxN = -1;
			}
		}
	}

	if (maxN == -1) {
		cout << maxN;
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				maxN = max(dist[i][j], maxN);
			}
		}

		cout << maxN;
	}

}