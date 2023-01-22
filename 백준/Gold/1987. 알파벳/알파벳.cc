#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool alpha[26];

void prt(vector <vector <char>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++)
			cout << vc[i][j] << "";
		cout << '\n';
	}
}

void init(vector <vector <char>> &vc) {
	/*for (int i = 0; i < 26; i++) {
		alpha[i] = false;
	}*/

	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); i++) {
			vc[i][j] = '0';
		}
	}
}

// A = 17

int Backtracking(const vector <vector <char>>& vc, vector <vector <char>>& visit, int i, int j) {
	pair <int, int> tmp;
	tmp.first = i;
	tmp.second = j;

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
				k = max(Backtracking(vc, visit, nX, nY), k);
			}
		}
	}

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
	vector <vector <char>> visit(vc);

	// prt(vc);

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
		}
	}

	visit[0][0] = '1';
	alpha[(vc[0][0] - '0' - 17)] = true;
	int gift = 1;

	cout << Backtracking(vc, visit, 0, 0) + gift;

}