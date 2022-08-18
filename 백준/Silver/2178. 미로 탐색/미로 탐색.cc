#include <bits/stdc++.h>
using namespace std;

int dirx[4] = { 1,0,0,-1 };
int diry[4] = { 0,1,-1,0 };

void pr(const vector<vector<int>> v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}


int bfs(vector <vector<int>> v1, vector<vector<int>> &visited, vector<vector<int>>& minD, int i, int j) {
	queue <pair<int, int>> q;
	pair<int, int> tmp;
	q.push({ i,j });
	visited[i][j] = 1;
	minD[i][j] = 1;

	int cnt = 1;

	while (!q.empty()) {
		cnt++;
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dirx[i];
			int nY = y + diry[i];
			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (visited[nX][nY] == 0 && v1[nX][nY] == 1) {
					visited[nX][nY] = 1;
					q.push({ nX, nY });
					minD[nX][nY] = minD[x][y] + 1;
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

	cin.ignore();

	vector<int> v2(m, 0);
	vector<vector<int>> v1(n, v2);
	vector<vector<int>> visit(v1);
	vector<vector<int>> minDist(v1);

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < m; j++) {
			v1[i][j] = s[j] - '0';
		}
	}

	bfs(v1, visit, minDist, 0, 0);

	cout << minDist[n - 1][m - 1];



}