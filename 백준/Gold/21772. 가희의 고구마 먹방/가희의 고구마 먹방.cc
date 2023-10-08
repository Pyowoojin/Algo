#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int lim;

bool IsValid(vector <vector <char>>& vc, int nX, int nY) {
	return (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size());
}

int Backtracking(vector <vector <char>> &vc, vector <vector <char>> &visited, int nowX, int nowY, int cnt) {
	if (cnt > lim)
		return 0;

	int sp = 0;

	if (vc[nowX][nowY] == 'S') {
		sp = 1;
		vc[nowX][nowY] = '.';
	}

	int l = 0;
	for (int k = 0; k < 4; k++) {
		int nX = nowX + dx[k];
		int nY = nowY + dy[k];

		if (IsValid(vc, nX, nY) && visited[nX][nY] != '1' && vc[nX][nY] != '#') {
			// visited[nX][nY] = '1';
			int maxN = Backtracking(vc, visited, nX, nY, cnt+1);
			l = max(maxN, l);
			visited[nX][nY] = '0';
		}
	}

	if (sp)
		vc[nowX][nowY] = 'S';

	return sp + l;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c; cin >> r >> c >> lim;
	vector <vector <char>> vc(r, vector <char>(c));
	vector <vector <char>> visited(vc);

	int startX = 0, startY = 0;

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
			if (vc[i][j] == 'G') {
				startX = i;
				startY = j;
			}
		}
	}

	cout << Backtracking(vc, visited, startX, startY, 0);
}

