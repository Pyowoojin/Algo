#include <bits/stdc++.h>
using namespace std;

char field[10][10];
bool ans;

void checkFive(int x, int y) {
	field[x][y] = 'X';
	// 가로줄 일 경우
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (cnt >= 5)
			ans = true;
		if (field[x][i] == 'X') {
			cnt++;
		}
		else
			cnt = 0;
	}
	if (cnt >= 5)
		ans = true;
	
	cnt = 0;
	// 세로줄일 경우
	for (int i = 0; i < 10; i++) {
		if (cnt >= 5)
			ans = true;
		if (field[i][y] == 'X') {
			cnt++;
		}
		else {
			cnt = 0;
		}
	}
	if (cnt >= 5)
		ans = true;

	cnt = 0;
	// 우측 대각일 경우
	// x가 0이나 y가 0이 될때까지 맨 위로 돌아가
	int i = x, j = y;
	while (i != 0 && j != 0) {
		i--;
		j--;
	}
	while (i < 10 && j < 10) {
		if (cnt >= 5)
			ans = true;
		if (field[i][j] == 'X') {
			cnt++;
		}
		else
			cnt = 0;
		i++; j++;
	}
	if (cnt >= 5)
		ans = true;

	// 왼쪽으로 대각
	// ↙ 이 방향으로 진행할거임
	i = x, j = y;
	cnt = 0;
	while (i != 0 && j != 9) {
		i--; j++;
	}
	while (i < 10 && j > -1) {
		if (cnt >= 5)
			ans = true;
		if (field[i][j] == 'X')
			cnt++;
		else
			cnt = 0;
		i++; j--;
	}
	if (cnt >= 5)
		ans = true;

	field[x][y] = '.';
}

void printField() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			field[i][j] = s[j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == '.') {
				checkFive(i, j);
			}
		}
	}

	cout << ans;
}