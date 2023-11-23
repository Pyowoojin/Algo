#include <bits/stdc++.h>
using namespace std;

bool visited[50][50];
bool visited2[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct retCells {
	int originalCells = 1;
	int changedCells = 0;
};

template <typename T>
bool IsValid(vector <T>& vc, int nX, int nY) {
	return (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size());
}

template <typename T>
retCells bfs(vector <T>& vc, int startX, int startY, int nowNum) {
	pair <int, int> temp;
	queue <pair <int, int>> que;
	que.push({ startX, startY });
	visited[startX][startY] = true;

	retCells retCells;

	if (vc[startX][startY].first != vc[startX][startY].second) {
		retCells.changedCells++;
	}

	while (!que.empty()) {
		temp = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nX = dx[i] + temp.first;
			int nY = dy[i] + temp.second;

			// 유효한 배열, 방문 X, 같은 값일 때 방문
			if (IsValid(vc, nX, nY) && !visited[nX][nY] && vc[nX][nY].first == nowNum) {
				// 원래 세포의 숫자와 다르다면 체크해야함
				if (vc[nX][nY].second != vc[nX][nY].first) {
					retCells.changedCells++;
				}
				retCells.originalCells++;
				visited[nX][nY] = true;
				que.push({ nX, nY });
			}
		}
	}

	return retCells;
}

template <typename T>
void normalbfs(vector <T>& vc, int startX, int startY, int nowNum) {
	pair <int, int> temp;
	queue <pair <int, int>> que;
	que.push({ startX, startY });
	visited2[startX][startY] = true;

	while (!que.empty()) {
		temp = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nX = dx[i] + temp.first;
			int nY = dy[i] + temp.second;

			// 유효한 배열, 방문 X, 같은 값일 때 방문
			if (IsValid(vc, nX, nY) && !visited2[nX][nY] && vc[nX][nY].second == nowNum) {
				visited2[nX][nY] = true;
				que.push({ nX, nY });
			}
		}
	}
}


int main() {
	int n, m; cin >> n >> m;
	vector <vector <pair <int, int>>> vc(n, vector <pair <int,int>>(m, {0,0}));

	int changedValue = 0;
	int originSector = 0;
	int changedSector = 0;
	bool validChange = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j].first;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j].second;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 방문 안 했으면 방문하러 출발!
			if (!visited[i][j]) {
				originSector++;
				retCells ret;
				ret = bfs(vc, i, j, vc[i][j].first);
				if (ret.changedCells != 0) {
					changedValue++;
					if (ret.changedCells != ret.originalCells)
					{
						validChange = false;
					}
				}
				// cout << "원래 개수 : " << ret.originalCells << " 바뀐 개수 :  " << ret.changedCells << '\n';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited2[i][j]) {
				changedSector++;
				normalbfs(vc, i, j, vc[i][j].second);
			}
		}
	}
	// cout << "원래 구역 : " << originSector << "바뀐 구역 : " << changedSector << endl;

	if (!validChange || changedValue >=2 || (changedSector > originSector)) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}


}