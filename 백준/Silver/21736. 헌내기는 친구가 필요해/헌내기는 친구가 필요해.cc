#include <bits/stdc++.h>
using namespace std;

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

int cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0,0 };
template <typename T>
void bfs(const vector <T>& v1, vector <T>& visit, int i, int j) {
	queue <pair <int, int>> q;
	q.push({ i,j });
	visit[i][j] = '1';

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nX = x + dx[k], nY = y + dy[k];
			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (visit[nX][nY] == '0' && v1[nX][nY] != 'X') {
					if (v1[nX][nY] == 'P')
						cnt++;
					visit[nX][nY] = '1';
					q.push({ nX, nY });
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector <char> v2(m, '0');
	vector <vector <char>> v1(n, v2);
	vector <vector <char>> visit(v1);

	pair <int, int> start;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'I')
				start = { i,j };
			v1[i][j] = s[j];
		}
	}

	bfs(v1, visit, start.first, start.second);

	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;

}