#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void prt(vector <vector<int>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end; cin >> start >> end;

	vector<int> visit(100000, 0);


	queue <pair<int, int>> q;
	int cnt = 0;
	q.push({ start, cnt });

	pair <int, int> now;

	while (!q.empty()) {
		now = q.front(); q.pop();

		if (now.first == end) {
			cout << now.second;
			break;
		}

		if (now.first - 1 > -1 && visit[now.first - 1] == 0) {
			visit[now.first - 1] = 1;
			q.push({ now.first - 1, now.second + 1 });
		}

		if (now.first + 1 <= 100000 && visit[now.first + 1] == 0) {
			visit[now.first + 1] = 1;
			q.push({ now.first + 1, now.second + 1 });
		}

		if (now.first * 2 <= 100000 && visit[now.first * 2] == 0) {
			visit[now.first * 2] = 1;
			q.push({ now.first * 2, now.second + 1 });
		}

	}

}