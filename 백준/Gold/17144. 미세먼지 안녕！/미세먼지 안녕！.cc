#include <bits/stdc++.h>
using namespace std;
int r, c, t;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int counterdx[4] = { 0, 1, 0, -1 };
int counterdy[4] = { 1, 0, -1, 0 };

int CalculateDust(vector<vector <int>>& vc) {
	int sum = 0;
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			if (vc[i][j] != -1) {
				sum += vc[i][j];
			}
		}
	}

	return sum;
}
bool IsValid(vector <vector <int>>& vc, int nX, int nY) {
	if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
		if (vc[nX][nY] != -1) {
			return true;
		}
	}
	return false;
}

bool IsValid2(vector <vector <int>>& vc, int nX, int nY) {
	if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
		return true;
	}
	return false;
}

void MoveOldToNew(vector <vector <int>>& vc, vector <vector <int>>& newVector, vector <vector <int>>& visited) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == 0) {
				newVector[i][j] = vc[i][j];
			}
		}
	}
}

void DisperseDust(vector <vector <int>>& vc) {
	vector <vector <int>> temp(r, vector <int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vc[i][j] != -1) {
				int cnt = 0;
				int val = vc[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nX = i + dx[k];
					int nY = j + dy[k];
					if (IsValid(vc, nX, nY)) {
						cnt++;
						temp[nX][nY] += val;
					}
				}
				temp[i][j] = temp[i][j] + vc[i][j] - (val * cnt);
			}
			else if (vc[i][j] == -1) {
				temp[i][j] = -1;
			}
		}
	}
	vc = temp;
}

void CirculationDust(vector <vector <int>>& vc, int i, int j, bool clockwise) {
	vector <vector <int>> temp(r, vector <int>(c, 0));
	vector <vector <int>> visited(temp);
	visited[i][j] = 1;
	int nowX = i, nowY = j;
	int val = 0;
	int dir = 0;

	while (true) {
		int nX = 0, nY = 0;
		if (clockwise) {
			nX = nowX + dx[dir];
			nY = nowY + dy[dir];
		}
		else {
			nX = nowX + counterdx[dir];
			nY = nowY + counterdy[dir];
		}

		if (!IsValid2(vc, nX, nY)) {
			dir++;
			continue;
		}

		if (vc[nX][nY] == -1) {
			temp[nX][nY] = -1;
			break;
		}
        
		val = vc[nX][nY];
		temp[nX][nY] = 0;
		if (vc[nowX][nowY] != -1) {
			temp[nX][nY] = vc[nowX][nowY];
		}
		nowX = nX, nowY = nY;
		visited[nX][nY] = 1;
	}
	MoveOldToNew(vc, temp, visited);
	vc = temp;
}

int main() {
	 cin >> r >> c >> t;
	 vector <vector <int>> vc(r, vector <int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> vc[i][j];
		}
	}

	while (t--) {
		DisperseDust(vc);
		for (int i = 0; i < r; i++) {
			if (vc[i][0] == -1) {
				CirculationDust(vc, i, 0, true);
				CirculationDust(vc, i + 1, 0, false);
				break;
			}
		}
	}
	cout << CalculateDust(vc);
}