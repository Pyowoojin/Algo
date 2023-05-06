#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int castle[100][100];
int dist[100][100];
bool visited[100][100];
int n, m, t;

int straithPrincess;
int gromPrincess;
int gromDist;
bool straightFinished;
bool gromFinished;
bool hasGrom;

void prt() {
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void bfs(int i, int j, bool has) {
	queue <pair <int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });

	while (!q.empty()) {
		tmp = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int nX = dx[k] + tmp.first;
			int nY = dy[k] + tmp.second;

			if (nX > -1 && nY > -1 && nX < n && nY < m) {
				if (!has && !visited[nX][nY] && castle[nX][nY] != 1) {
					visited[nX][nY] = true;
					q.push({ nX, nY });
					dist[nX][nY] += 1 + dist[tmp.first][tmp.second];
					if (castle[nX][nY] == 2) {
						hasGrom = true;
						gromDist = dist[nX][nY];
					}
					if (nX == n - 1 && nY == m - 1) {
						straithPrincess = dist[nX][nY];
						straightFinished = true;
						break;
					}
				}
				else if (has && !visited[nX][nY]) {
					visited[nX][nY] = true;
					q.push({ nX,nY });
					dist[nX][nY] += 1 + dist[tmp.first][tmp.second];
					if (nX == n - 1 && nY == m - 1) {
						gromPrincess = dist[nX][nY];
						gromFinished = true;
						break;
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> t;
	int gromX = 0, gromY = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castle[i][j];
			if (castle[i][j] == 2) {
				gromX = i, gromY = j;
			}
		}
	}


	bfs(0, 0, 0);
	if (hasGrom) {
		init();
		bfs(gromX, gromY, 1);
	}

	int ans = 0x7fffffff;

	if (straightFinished)
		ans = min(gromDist + gromPrincess, straithPrincess);
	else if (gromFinished)
		ans = gromDist + gromPrincess;

	if (ans <= t)
		cout << ans;
	else
		cout << "Fail";
	
}