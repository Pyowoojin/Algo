#include <bits/stdc++.h>
using namespace std;

int success = 1;

bool chk(int m, pair<int, int> &p) {
	if ((p.first >= m || p.second >= m) || (p.first < 0 || p.second < 0)) {
		success = -1;
		return false;
	}
	else
		return true;
}

void output(const vector<vector<int>>& a, const pair<int,int> &b) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (b.first == i && b.second == j)
				cout << "1" << " ";
			else
				cout << "0" << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// turn 0 -> 왼쪽으로 90도 회전, 1 -> 오른쪽 90도
	// move n -> 보고 있는 방향으로 n만큼 이동
	int n, m; cin >> m >> n;
	
	// 맵을 그릴 2차원 VECTOR
	vector <int> v2(m, 0);
	vector <vector<int>> v1(m, v2);
	
	// 명령어를 저장할 queue
	queue <pair<string, int>> q;
	
	// 명령어를 뽑을 tmpQueue
	pair<string, int > out;

	/* 현재 위치 출력해보기 -> 왼쪽 맨 밑 = (n-1, 0);
	 상하좌우를 표현하는 방법은? 
	 상 : n을 감소시킴, 하 : n을 증가시킴
	 좌 : m을 감소시킴, 우 : m을 증가시킴*/

	// 방향을 표시하는 방법은? 
	// 1 -> 상, 2-> 하, 3-> 좌, 4-> 우?
	// 상-> 90 하-> 270 좌 -> 0(360) 우 -> 180
	int direction = 180;

	pair <int, int> now = { m - 1, 0 };


	// 명령어 입력
	for (int i = 0; i < n; i++) {
		string s; int z; cin >> s >> z;
		q.push({ s,z });
	}

	// output(v1, now);

	// 명령어 실행
	int moveCnt = 0;

	while(!q.empty()) {
		out = q.front(); q.pop();
		if (out.first == "MOVE") {
			if (direction == 90) {
				moveCnt = out.second;
				now.first -= moveCnt;
				chk(m, now);
			}
			else if (direction == 270) {
				moveCnt = out.second;
				now.first +=moveCnt;
				chk(m, now);
			}
			else if (direction == 0) {
				moveCnt = out.second;
				now.second -= moveCnt;
				chk(m, now);
			}
			else if (direction == 180) {
				moveCnt = out.second;
				now.second += moveCnt;
				chk(m, now);
			}
		}
		// 0이면 왼쪽 90 1이면 오른쪽 90
		else {
			if (out.first == "TURN") {
				if (out.second == 0)
					direction = (360 - 90 + direction) % 360;
				else if (out.second == 1)
					direction = (360 + 90 + direction) % 360;
			}
		}

		// output(v1, now);

		if (success == -1)
			break;
	}

	if (success == -1)
		cout << success;
	else {
		// cout << "???" << endl;
		cout << now.second << " " << m - 1 - now.first;
	}

}