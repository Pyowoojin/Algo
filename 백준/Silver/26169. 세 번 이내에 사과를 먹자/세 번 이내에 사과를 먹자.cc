#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool appleClear = false;

bool IsValid(vector <vector <int>>& vc, int nX, int nY) {
	return (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size());
}

void Apple(vector <vector <int>>& vc, vector <vector <int>>& visit, int nowX, int nowY, int moveCount, int appleCount) {
	int bHasApple = 0;

	if (vc[nowX][nowY] == 1) {
		bHasApple = 1;
	}

	if (appleCount + bHasApple == 2) {
		appleClear = true;
		return;
	}

	if (moveCount == 3) {
		return;
	}

	vc[nowX][nowY] = -1;
	visit[nowX][nowY] = 1;

	for (int i = 0; i < 4; i++) {
		int nX = dx[i] + nowX;
		int nY = dy[i] + nowY;
		if (IsValid(vc, nX, nY) && visit[nX][nY] == 0 && vc[nX][nY] != -1) {
			Apple(vc, visit, nX, nY, moveCount+1, appleCount + bHasApple);
		}
	}

	if (bHasApple) {
		vc[nowX][nowY] = 1;
	}
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

	cout << appleClear;

}