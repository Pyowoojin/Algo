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
void init(vector <T>& vec) {
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

	int n, m; cin >> n >> m;

	vector <int> mp2(m, 0);
	vector <vector <int>> mp(n, mp2);
	vector <vector <int>> visit(mp);
	vector <vector <int>> chkIce(mp);

	int maxN = -1;


	// Input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c; cin >> c;
			mp[i][j] = c;
			if (maxN < c)
				maxN = c;
		}
	}

	int ans = 0;
	int realAns = 0;
	bool flag = true;
	while (1) {

		int landCnt = 0;

		// 처음부터 2개로 분리된 섬 체크 하기 위해 섬 체크 bfs를 맨 위로 놓음
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] > 0 && visit[i][j] == 0) {
					landCnt++;
					bfs(mp, visit, i, j);
					flag = true;
				}
			}
		}

		if (flag == 0)
		{
			break;
		}

		// 섬이 2개 이상 된다면, break;
		if (landCnt >= 2) {
			realAns = ans;
			break;
		}

		// 주변의 바다 개수를 세어주는 for문
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] != 0) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nX = i + dx[k];
						int nY = j + dy[k];

						// 바다 위치를 세고, 한꺼번에 바꿔주기 위해서 chkIce 배열에 따로 저장해놓음
						if (nX > -1 && nY > -1 && nX < n && nY < m) {
							
							// 상하좌우의 지역이 0보다 작다면(음수도 포함시킴) 녹여줄 것임
							if (mp[nX][nY] <= 0)
								chkIce[i][j]++;
						}
					}
				}
			}
		}

		// 각 지역마다 주변 바다 크기만큼 빙산을 녹여준다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] >= 0) {
					mp[i][j] -= chkIce[i][j];
				}
			}
		}

		// prt(mp);

		// 방문배열 초기화, 주변 바다 체크 배열 초기화
		init(visit);
		init(chkIce);
		maxN--;
		// 년도 증가
		ans++;
		flag = false;
	}

	cout << realAns;

}