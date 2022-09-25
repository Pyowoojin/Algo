#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int dx[2] = { -1,1 };

int parent[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end; cin >> start >> end;
	vector <bool> visit(100001, 0);
	queue <pair<int, int>> q;
	pair<int, int> tmp;
	q.push({ start, 0 });
	visit[0] = 1;

	vector <int> path;

	if (start <= end) {
		while (!q.empty()) {
			tmp = q.front(); q.pop();

			if (tmp.first == end) {
				cout << tmp.second;
				int idx = tmp.first;
				while (idx != start) {
					path.push_back(idx);
					idx = parent[idx];
				}
				path.push_back(start);

				break;
			}

			int mX = tmp.first * 2;
			if (mX > -1 && mX < 100001) {
				if (visit[mX] == 0) {
					q.push({ mX, tmp.second + 1 });
					visit[mX] = 1;
					parent[mX] = tmp.first;
				}
			}

			for (int i = 0; i < 2; i++) {
				int nX = tmp.first + dx[i];
				if (nX > -1 && nX < 100001) {
					if (visit[nX] == 0) {
						q.push({ nX, tmp.second + 1 });
						visit[nX] = 1;
						parent[nX] = tmp.first;
					}
				}
			}
		}

		cout << endl;

		for (int i = path.size() - 1; i > -1; i--) {
			cout << path[i] << " ";
		}
	}
	else {
		cout << start - end << endl;
		for (int i = start; i >= end; i--) {
			cout << i << " ";
		}
	}
}