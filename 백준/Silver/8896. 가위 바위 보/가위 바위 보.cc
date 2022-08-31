#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

char robot[10][30];

// 승패를 결정하기 위한 가위바위보 배열
// 순서대로 가위, 바위, 보의 유무를 나타냄
bool rsp[3];

char chk() {
	// 무승부일때
	int drawCnt = 0;
	for (int i = 0; i < 3; i++) {
		if (rsp[i] == 1)
			drawCnt++;
	}
	if (drawCnt == 3 || drawCnt == 1) {
		return 'D';
	}

	// 가위와 바위
	if (rsp[0] && rsp[1]) {
		return 'R';
	}

	// 가위와 보자기
	if (rsp[0] && rsp[2]) {
		return 'S';
	}

	// 바위와 보자기
	if (rsp[1] && rsp[2]) {
		return 'P';
	}

	return 'D';
}

int loser(char ar, int people, int round, int roundSize) {
	if (ar == 'D')
		return 0;
	for (int i = 0; i < people; i++) {
		if (robot[i][round] != ar) {
			for (int k = round; k < roundSize; k++) {
				robot[i][k] = 'X';
			}
		}
	}

	return 0;
}

void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			robot[i][j] = ' ';
		}
	}
	fill(rsp, rsp + 3, 0);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	while (tc) {

		int n; cin >> n;
		cin.ignore();
		int roundSize = 0;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			roundSize = s.length();
			for (int j = 0; j < s.length(); j++) {
				robot[i][j] = s[j];
			}
		}

		// i -> 몇번째 라운드인지
		for (int i = 0; i < roundSize; i++) {
			// 참가자 숫자만큼
			for (int j = 0; j < n; j++) {
				// 가위 바위 보 중 무엇을 냈는지 체크하여 rsp배열을 바꿔줌
				if (robot[j][i] == 'S')
					rsp[0] = 1;
				if (robot[j][i] == 'R')
					rsp[1] = 1;
				if (robot[j][i] == 'P')
					rsp[2] = 1;

				// loser(chk(), n, i);
			}
			// cout << chk() << endl;
			loser(chk(), n, i, roundSize);
			fill(rsp, rsp + 3, 0);
		}

		// 승자 출력
		int winnerCnt = 0;
		int winner = 0;

		for (int i = 0; i < n; i++) {
			if (robot[i][roundSize - 1] != 'X') {
				winnerCnt++;
				winner = i + 1;
			}
		}

		if (winnerCnt > 1)
			cout << "0\n";
		else
			cout << winner << '\n';

		init();

		tc--;
	}
}