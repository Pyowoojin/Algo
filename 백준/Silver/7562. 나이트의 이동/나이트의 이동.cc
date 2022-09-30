#include <bits/stdc++.h>
using namespace std;

int myMap[300][300];
int visited[300][300];
int dx[8] = { -2,-2,-1,1,2,2,1,-1 };
int dy[8] = { -1,1,2,2,1,-1,-2,-2 };

int nbfs(int i, int j, int sz, int start, int end) {
	queue <tuple <int, int, int>> q;
	tuple<int, int, int> tmp;
	q.push({ i,j,0 });
	visited[i][j] = 1;
	int cnt = 0;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = get<0>(tmp), y = get<1>(tmp);

		if (start == x && y == end) {
			cnt = get<2>(tmp);
			break;
		}

		for (int k = 0; k < 8; k++) {
			int nX = x + dx[k];
			int nY = y + dy[k];

			if (nX > -1 && nY > -1 && nX < sz && nY < sz) {
				if (visited[nX][nY] == 0) {
					q.push({ nX, nY, get<2>(tmp) + 1 });
					visited[nX][nY] = 1;
				}
			}
		}
	}

	return cnt;
}

void init2DArr(int arr[][300]) {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			arr[i][j] = 0;
		}
	}
}

// A = 17
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	while (tc) {
		int n; cin >> n;
		int start, end; cin >> start >> end;
		int desStart, desEnd; cin >> desStart >> desEnd;

		cout << nbfs(start, end, n, desStart, desEnd) << '\n';
		init2DArr(myMap);
		init2DArr(visited);

		tc--;
	}

}