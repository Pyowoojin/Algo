#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool alpha[26];


// 디버깅을 위한 print 함수
void prt(vector <vector <char>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++)
			cout << vc[i][j] << "";
		cout << '\n';
	}
}

// A = 17

int Backtracking(const vector <vector <char>>& vc, int i, int j) {
	pair <int, int> tmp;
	tmp.first = i;
	tmp.second = j;

	// 방문하지 않은 지역이라면, 방문 처리를 하고 gift를 1 증가시킴
	int sum = 0;
	if (!alpha[(vc[i][j] - '0' - 17)]) {
		alpha[(vc[i][j] - '0' - 17)] = true;
		sum = 1;
	}

	int k = 0;
	for (int i = 0; i < 4; i++) {
		int nX = dx[i] + tmp.first;
		int nY = dy[i] + tmp.second;

		if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
			if ((alpha[vc[nX][nY] - '0' - 17]) == false) {
				k = max(Backtracking(vc, nX, nY), k);
			}
		}
	}

	// 백트래킹을 위해 현재 방문한 지역은 방문 처리를 취소함
	alpha[(vc[i][j] - '0' - 17)] = false;

	return sum + k;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c; cin >> r >> c;

	vector <char> vc2(c, '0');
	vector <vector <char>> vc(r, vc2);

	// prt(vc);

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
		}
	} // 예제 입력 끝


	// (0,0)은 방문 처리하고 선물 + 1
	alpha[(vc[0][0] - '0' - 17)] = true;
	int gift = 1;

	// 백트래킹 수행 후 출력
	cout << Backtracking(vc, 0, 0) + gift;

}