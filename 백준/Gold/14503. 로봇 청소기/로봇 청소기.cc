#include <bits/stdc++.h>
using namespace std;

int dir;

// 상, 우, 하, 좌
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Print(vector <vector <int>>& room) {
	for (int i = 0; i < room.size(); i++) {
		for (int j = 0; j < room[0].size(); j++) {
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RotateDir() {
	if (dir > 0)
		dir--;
	else if (dir == 0)
		dir = 3;
}

bool CanGo(vector <vector <int>>& room, int nX, int nY) {
	if (room[nX][nY] == 0)
		return true;
	return false;
}

// 범위를 벗어나지 않는지 확인
bool IsValid(vector <vector <int>>& room, int nX, int nY) {
	if (nX < 0 || nY < 0 || nX >= room.size() || nY >= room[0].size())
		return false;
	return true;
}

bool CanIReverse(vector <vector <int>>& room, int nX, int nY) {
	// 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가?
	// -> 한 칸 후진 했을 때 벽이 아닌가?
	if (room[nX][nY] != 1) {
		return true;
	}
	return false;
}

// 주변 4칸 중 청소되지 않은 칸이 있는지 확인
bool CanICleaning(vector <vector <int>>& room, int nowX, int nowY) {
	for (int i = 0; i < 4; i++) {
		int nX = nowX + dx[i];
		int nY = nowY + dy[i];

		if (IsValid(room, nX, nY)) {
			if (room[nX][nY] == 0)
				return true;
		}
	}
	return false;
}

int CleanTheRoom(vector <vector <int>>& room, int nowX, int nowY) {

	int CleaningCount = 0;

	while (1) {
		// 1. 현재칸이 청소되지 않은 경우 현재 칸을 청소한다.
		if (room[nowX][nowY] == 0) {
			room[nowX][nowY] = -1;
			CleaningCount++;
		}
		else {
			// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
			if (!CanICleaning(room, nowX, nowY)) {
				int nX = nowX - dx[dir];
				int nY = nowY - dy[dir];

				// 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가?
				if (IsValid(room, nX, nY) && CanIReverse(room, nX, nY)) {
					// 후진할 수 있다면 한 칸 후진 후 1번으로 돌아간다.
					nowX = nX;
					nowY = nY;
				}
				// 후진 할 수 없다면 종료
				else {
					return CleaningCount;
				}
			}

			// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는 경우
			else if (CanICleaning(room, nowX, nowY)) {
				// 3-1. 반시계 방향으로 90도 회전한다.
				RotateDir();
				// 3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸이면 한 칸 전진
				int nX = nowX + dx[dir];
				int nY = nowY + dy[dir];
				if (IsValid(room, nX, nY) && CanGo(room, nX, nY)) {
					nowX = nX;
					nowY = nY;
					// 3-3. 아니라면 다시 방향을 회전한다.
				}
			}
		}
	}
}

int main() {
	int n, m; cin >> n >> m;

	// -1 = 청소 O, 0 = 청소 X, 1 = 벽
	// dir :: 0 - 상 / 1 - 우 / 2 - 하 / 3 - 좌

	vector <vector <int>> vc(n, vector <int>(m, 0));
	int startX, startY;
	
	cin >> startX >> startY >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j];
		}
	}

	cout << CleanTheRoom(vc, startX, startY);
}