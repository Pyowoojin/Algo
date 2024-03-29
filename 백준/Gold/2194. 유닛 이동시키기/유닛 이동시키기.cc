#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct Point {
	int dist;
	int x;
	int y;
};

int sX, sY;
int eX, eY;

bool ans = false;
int cnt = 0;

bool isValid(int nX, int nY, vector <vector <int>>& vc, int a, int b) {
	// 맵 안인지 확인
	if (nX > -1 && nY > -1 && nX + a - 1 < vc.size() && nY + b - 1 < vc[0].size()) {
		// 지나갈 수 있는 공간인지 확인
		for (int i = nX; i < nX + a; i++) {
			for (int j = nY; j < nY + b; j++) {
				if (vc[i][j] == 1) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

void bfs(vector <vector <int>>& vc, vector <vector <int>>& visited, int a, int b) {
	Point tmp;
	queue <Point> q;
	q.push({ 0, sX,sY });
	visited[sX][sY] = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int nX = dx[k] + tmp.x;
			int nY = dy[k] + tmp.y;

			if (isValid(nX, nY, vc, a, b) && visited[nX][nY] == 0) {
				visited[nX][nY] = 1;
				if (nX == eX && nY == eY) {
					ans = true;
					cnt = tmp.dist;
				}
				q.push({ tmp.dist + 1, nX, nY });
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, a, b, k;
	cin >> n >> m >> a >> b >> k;

	vector <vector <int>> vc(n, vector <int>(m));
	vector <vector <int>> visited(vc);

	for (int i = 0; i < k; i++) {
		int ka, kb; cin >> ka >> kb;
		vc[ka - 1][kb - 1] = 1;
	}

	int startX, startY; cin >> startX >> startY;
	startX--;
	sX = startX;
	startY--;
	sY = startY;

	cin >> startX >> startY;
	startX--;
	eX = startX;
	startY--;
	eY = startY;

	bfs(vc, visited, a, b);

	if (ans) {
		cout << cnt + 1;
	}
	else
		cout << "-1";
}