#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0, 0 };

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

template <typename T>
void bfs(vector <T>& mp, vector <T>& visit, int i, int j) {
	queue <pair<int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;

		for (int k = 0; k < 4; k++) {
			int nX = x + dx[k];
			int nY = y + dy[k];

			if (nX < mp.size() && nY < mp[0].size() && nX > -1 && nY > -1) {
				if (visit[nX][nY] == 0 && mp[nX][nY] > 0) {
					q.push({ nX,nY });
					visit[nX][nY] = 1;
				}
			}
		}
	}
}

template <typename T>
void init(vector <T> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {
			vec[i][j] = 0;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector <int> vc;
	int total = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
		total += c;
	}

	sort(vc.begin(), vc.end());

	int i = 0;
	while (i < vc.size()) {
		total -= vc[i];
		ans += total * vc[i];
		i++;
	}

	cout << ans;



}