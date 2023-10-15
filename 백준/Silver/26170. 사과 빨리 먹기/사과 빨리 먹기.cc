#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool appleClear = false;
int minMove = 0x7fffffff;

bool IsValid(vector <vector <int>>& vc, int nX, int nY) {
	return (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size());
}

void Apple(vector <vector <int>>& vc, vector <vector <int>>& visit, int nowX, int nowY, int numOfApple, int moveCount) {
	
	visit[nowX][nowY] = 1;

	int bIsApple = 0;

	if (vc[nowX][nowY] == 1) {
		bIsApple = 1;
	}

	// 지나온 칸은 장애물로 변한다.
	vc[nowX][nowY] = -1;
	
	if (numOfApple + bIsApple >= 3) {
		appleClear = true;
		if (moveCount < minMove) {
			minMove = moveCount;
		}
		vc[nowX][nowY] = 1;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nX = nowX + dx[i];
		int nY = nowY + dy[i];
		if (IsValid(vc, nX, nY) && vc[nX][nY] != -1 && visit[nX][nY] == 0) {
			visit[nX][nY] = 1;
			Apple(vc, visit, nX, nY, numOfApple + bIsApple, moveCount + 1);
			visit[nX][nY] = 0;
		}
	}
	// 사과 칸이었다면 1로 바꿔주고
	if (bIsApple) {
		vc[nowX][nowY] = 1;
	}
	// 아니라면 0으로 바꿔줌
	else {
		vc[nowX][nowY] = 0;
	}

	visit[nowX][nowY] = 0;
}

int main() {
	vector <vector <int>> vc(5, vector <int>(5, 0));
	vector <vector <int>> visit(vc);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> vc[i][j];
		}
	}
	int startX = 0, startY = 0;
	cin >> startX >> startY;

	Apple(vc, visit, startX, startY, 0, 0);

	if (appleClear)
		cout << minMove;
	else
		cout << "-1";
}