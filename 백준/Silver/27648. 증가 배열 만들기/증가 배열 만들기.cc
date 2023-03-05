#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void prt(vector <vector <int>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << endl;
	}
}

void bfs(int startX, int startY, vector <vector <int>>& vc, vector <vector <int>>& visited, vector <vector <int>>& dist) {
	pair <int, int> tmp;
	queue <pair <int, int>> q;
	q.push({ startX, startY });
	visited[startX][startY] = 1;
	dist[startX][startY] = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nX = tmp.first + dx[k];
			int nY = tmp.second + dy[k];

			if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
				if (visited[nX][nY] == 0) {
					q.push({ nX,nY });
					visited[nX][nY] = 1;
					dist[nX][nY] += dist[tmp.first][tmp.second] + 1;
				}
			}
		}
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k; cin >> n >> m >> k;

	vector <int> vc2(m, 0);
	vector <vector <int>> vc(n,vc2);
	vector <vector <int>> visited(vc);
	vector <vector <int>> dist(vc);

	int startX = 0, startY = 0;

	bfs(startX, startY, vc, visited, dist);

	if (dist[n - 1][m - 1] <= k) {
		cout << "YES\n";
		prt(dist);
	}
	else
		cout << "NO";

}