#include <bits/stdc++.h>
#define ll long long
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

	int start, end; cin >> start >> end;
	/*bool* visit = new bool[end + 1];
	fill(visit, visit + end + 1, 0);*/

	int cnt = 0;

	queue <pair<ll, ll>> q;
	pair <ll, ll> tmp;
	q.push({ start, 0 });
	
	bool flag = false;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		long long now = tmp.first;
		if (now == end) {
			cout << tmp.second+1;
			flag = true;
			break;
		}
		long long next1 = now * 2;
		long long next2 = now * 10 + 1;

		if (next1 <= end) {
			q.push({ next1, tmp.second + 1 });
			// visit[next1] = 1;
		}
		if (next2 <= end) {
			q.push({ next2, tmp.second + 1 });
			// visit[next2] = 1;
		}
	}

	if (flag == false)
		cout << "-1";

}