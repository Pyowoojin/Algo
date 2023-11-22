#include <bits/stdc++.h>
using namespace std;

// 빈 공간 = 0, 벽 = 1, 물 = 2

void prt(vector <vector <int>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << endl;
	}
}

void fillTheWater(vector <vector<int>>& vc, int start, int end, int height) {
	for (int i = height; i < vc.size(); i++) {
		for (int j = start; j <= end; j++) {
			if (vc[i][j] == 0) {
				vc[i][j] = 2;
			}
		}
	}
}

int findHighestBlock(vector <vector <int>>& vc, int pos) {
	int Highest = -1;
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i][pos] == 1) {
			Highest = i;
			break;
		}
	}
	return Highest;
}

void leftandright(vector <vector <int>>& vc, int originHeight, int originWidth){
	// 왼쪽으로 이동하며 벽이 존재하는지 확인
	int leftside = -1, rightside = -1;
	for (int i = originWidth; i >= 0; i--) {
		// 벽을 발견한다면 물을 채우자.
		if (vc[originHeight][i] == 1) {
			leftside = i;
		}
	}

	// 벽이 존재한다면 물을 채우러 ㄱㄱ
	if (leftside != -1) {
		fillTheWater(vc, leftside, originWidth, originHeight);
	}

	// 오른쪽으로 이동하며 벽이 존재하는지 확인
	for (int i = originWidth; i < vc[0].size(); i++) {
		// 벽을 발견한다면 물을 채우자.
		if (vc[originHeight][i] == 1) {
			rightside = i;
		}
	}

	// 벽이 존재한다면 물을 채우러 ㄱㄱ
	if (rightside != -1) {
		fillTheWater(vc, originWidth, rightside, originHeight);
	}
}

int main() {
	int h, w; cin >> h >> w;
	vector <vector <int>> vc(h, vector <int>(w, 0));

	for (int i = 0; i < w; i++) {
		int c; cin >> c;
		for (int j = h - 1; j >= h - c; j--) {
			vc[j][i] = 1;
		}
	}

	for (int i = 0; i < w; i++) {
		int highest = findHighestBlock(vc, i);
		// 해당 열에 블록이 존재한다면 좌 우로 이동하며
		// 물을 채울 수 있는지 확인한다.
		if (highest != -1) {
			leftandright(vc, highest, i);
		}
	}

	int ans = 0;

	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			if (vc[i][j] == 2) {
				ans++;
			}
		}
	}

	cout << ans;
}