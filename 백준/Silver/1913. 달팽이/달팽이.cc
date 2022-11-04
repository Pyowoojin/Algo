#include <bits/stdc++.h>
using namespace std;

// 위, 오른쪽, 아래, 왼쪽
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

template <typename T>
void prt(const vector <T>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << '\n';
	}
	// cout << '\n';
}

int direction[4] = { 0,1,2,3 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int target; cin >> target;

	vector <int> vc1(n, 0);
	vector <vector <int>> vc(n, vc1);

	int number = 2;
	int len = 1;
	int jCnt = 0, dir = 0;
	int mid = n / 2;
	vc[mid][mid] = 1;
	int nowX = mid, nowY = mid;
	pair <int, int> ans = { -1,-1 };
	while (1) {
		if (nowX <= -1 || nowY <= -1 || nowX >= n || nowY >= n)
			break;

		// 2 꺾을 때 마다 len 1씩 늘려주기
		if (jCnt == 2) {
			len++;
			jCnt = 0;
		}
		if (dir == 4) {
			dir = 0;
		}
		
		for (int i = 0; i < len; i++) {
			nowX += dx[dir];
			nowY += dy[dir];

			if (nowX > -1 && nowY > -1 && nowX < n && nowY < n) {
				vc[nowX][nowY] = number;
				if (number == target) {
					ans = { nowX, nowY };
				}
				number++;
			}
		}
		dir++;
		jCnt++;
	}
	prt(vc);
	if (ans.first == -1) {
		cout << mid +1 << " " << mid + 1;
	}
	else
		cout << ans.first + 1 << " " << ans.second + 1;
}


