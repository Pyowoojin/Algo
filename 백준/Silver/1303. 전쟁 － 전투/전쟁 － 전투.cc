#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

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

int bfs(vector <vector<char>>& v1, vector<vector<char>>& visit, int i, int j, char findchar) {
	queue <pair<int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });
	visit[i][j] = '1';
	int cnt = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nX = x + dx[k];
			int nY = y + dy[k];

			if(nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()){
				if (visit[nX][nY] == '0' && v1[nX][nY] == findchar) {
					cnt++;
					q.push({ nX,nY });
					visit[nX][nY] = '1';
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector <char> v2(n, '0');
	vector <vector<char>> v1(m, v2);
	vector <vector<char>> visit(v1);


	// input for loop
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v1[i][j] = s[j];
		}
	}

	int wPower = 0, bPower = 0;


	// Power check for loop
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == '0' && v1[i][j] == 'W') {
				int tmp = bfs(v1, visit, i, j, 'W');
				tmp = tmp * tmp;
				wPower += tmp;
			}
			else if (visit[i][j] == '0' && v1[i][j] == 'B') {
				int tmp = bfs(v1, visit, i, j, 'B');
				tmp = tmp * tmp;
				bPower += tmp;
			}
		}
	}

	cout << wPower << " " << bPower;

}