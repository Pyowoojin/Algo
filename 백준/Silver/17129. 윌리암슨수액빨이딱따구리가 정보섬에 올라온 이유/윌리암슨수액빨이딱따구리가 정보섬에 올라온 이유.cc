#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
map <string, int> mp;

bool comp(pair <string, int>& a, pair <string, int>& b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

template <typename T>
void prt(vector <T>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << '\n';
	}
}

bool isValid(vector <vector <int>>& vc, int nX, int nY) {
	return (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size());
}

void bfs(vector <vector <int>>& vc, vector <vector<int>>& visited, vector <vector <int>> &mind, int i, int j) {
	pair <int, int> tmp;
	queue <pair <int, int>> q;
	q.push({ i,j });
	
	while (!q.empty()) {
		tmp = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int nX = tmp.first + dx[k];
			int nY = tmp.second + dy[k];

			if (isValid(vc, nX, nY)) {
				if (vc[nX][nY] != 1 && visited[nX][nY] == 0) {
					mind[nX][nY] = mind[tmp.first][tmp.second] + 1;
					q.push({ nX,nY });
					visited[nX][nY] = 1;
					if (vc[nX][nY] == 3) {
						mp["a"] = mind[nX][nY];
					}
					else if (vc[nX][nY] == 4) {
						mp["b"] = mind[nX][nY];
					}
					else if (vc[nX][nY] == 5) {
						mp["c"] = mind[nX][nY];
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m; cin >> n >> m;

	mp.insert({ "a", 90000001 });
	mp.insert({ "b", 90000001 });
	mp.insert({ "c", 90000001 });

	vector <int> vc2(m, 0);
	vector <vector <int>> vc(n, vc2);
	vector <vector <int>> visited(vc);
	vector <vector <int>> minD(vc);

	int startX = 0, startY = 0;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j] - '0';
			// 시작점 위치 삽입
			if (vc[i][j] == 2) {
				startX = i, startY = j;
			}
		}
	}

	bfs(vc, visited, minD, startX, startY);

	vector <pair <string, int>> sorting(mp.begin(), mp.end());
	
	sort(sorting.begin(), sorting.end(), comp);

	for (int i = 0; i < sorting.size(); i++) {
		if (sorting[i].second != 90000001) {
			cout << "TAK\n" << sorting[i].second;
			break;
		}

		if (i + 1 == sorting.size())
			cout << "NIE";
	}
}