#include <bits/stdc++.h>
using namespace std;

int sheep, wolf;

bool visited[251][251];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct SheepAndWolf {
	int sheepCnt;
	int wolfCnt;
};

SheepAndWolf bfs(vector <vector <char>>& vc, int startX, int startY) {
	pair <int, int> temp;
	queue <pair <int, int>> q;
	q.push({ startX, startY });
	visited[startX][startY] = true;
	SheepAndWolf saw = { 0,0 };

	while (!q.empty()) {
		temp = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nX = temp.first + dx[i];
			int nY = temp.second + dy[i];

			if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
				if (!visited[nX][nY] && vc[nX][nY] != '#') {
					q.push({ nX,nY });
					visited[nX][nY] = true;
					if (vc[nX][nY] == 'v') {
						saw.wolfCnt += 1;
					}
					else if (vc[nX][nY] == 'o') {
						saw.sheepCnt += 1;
					}
				}
			}
		}
	}

	return saw;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int r, c; cin >> r >> c;
	vector <vector <char>> vc(r, vector <char>(c, '.'));

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
		}
	}

	SheepAndWolf MainSAW = { 0,0 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] && vc[i][j] != '#') {
				MainSAW = bfs(vc, i, j);
				if (vc[i][j] == 'v')
					MainSAW.wolfCnt += 1;
				else if (vc[i][j] == 'o')
					MainSAW.sheepCnt += 1;

				if (MainSAW.sheepCnt > MainSAW.wolfCnt)
					sheep += MainSAW.sheepCnt;
				else
					wolf += MainSAW.wolfCnt;
			}
		}
	}
	cout << sheep << " " << wolf;
}