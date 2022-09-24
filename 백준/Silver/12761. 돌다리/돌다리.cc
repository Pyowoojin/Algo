#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

template <typename T>
void prt2d(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	cin >> a >> b >> n >> m;

	int dx[8] = { -1,1,a,b, -a , -b, a,b };

	vector <int> visit(1000000, 0);

	queue <pair <int, int>> q;
	pair<int, int> tmp;
	q.push({ n, 0 });

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int now = tmp.first;
		if (m == now) {
			// cout << m << "  그리고   " << now << endl;
			cout << tmp.second;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nX = 0;
			if (i > 5) nX = tmp.first * dx[i];
			else nX = tmp.first + dx[i];

			if ((nX > -1 && nX < 100001) && visit[nX] == 0) {
				q.push({ nX, tmp.second + 1 });
				visit[nX] = 1;
			}
		}

	}


}