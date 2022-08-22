#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void prt(const vector<vector<int>> &v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1.size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs(const vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j) {
	queue <pair <int, int>> q;
	pair<int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;
	int house = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1.size()) {
				if (visit[nX][nY] == 0 && v1[nX][nY] == 1) {
					house++;
					visit[nX][nY] = 1;
					q.push({ nX, nY });
				}
			}
		}

	}

	return house;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> v2(n, 0);
	vector<vector<int>> v1(n, v2);
	vector<vector<int>> visit(v1);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v1[i][j] = s[j] - '0';
		}
	}

	int group = 0;
	vector <int> houslist;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] != 1 && v1[i][j] == 1) {
				group++;
				houslist.push_back(bfs(v1, visit, i, j));
			}
		}
	}

	cout << group << endl;
	sort(houslist.begin(), houslist.end());
	for (auto i : houslist)
		cout << i << endl;

}