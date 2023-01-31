#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int totalTime = 0;
int maxCheese;

template <typename T>
void prt(vector <T> vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void ZeroDotZero(vector <vector <int>>& vc, vector <vector <int>>& visited, int i, int j) {
	if (!maxCheese)
		return;
	pair <int, int> tmp;
	tmp.first = i;
	tmp.second = j;
	queue <pair <int, int>> qu;
	qu.push(tmp);

	totalTime++;

	while (!qu.empty()) {
		tmp = qu.front();
		qu.pop();
		
		for (int i = 0; i < 4; i++) {
			int nX = tmp.first + dx[i];
			int nY = tmp.second + dy[i];

			if (nX > -1 && nY > -1 && nX < vc.size() && nY < vc[0].size()) {
				if (vc[nX][nY] == 1) {
					vc[nX][nY] = 2;
					maxCheese--;
				}

				if (visited[nX][nY] == 0 && vc[nX][nY] == 0) {
					visited[nX][nY] = 1;
					qu.push({ nX,nY });
				}
			}
		}
	}
}

pair <int,int> TwoToZero(vector <vector <int>>& vc) {
	int ni = -1, nj = -1;
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			if (vc[i][j] == 2) {
				vc[i][j] = 0;
				ni = i, nj = j;
			}
		}
	}
	return { ni, nj };
}

void init(vector <vector <int>>& visited)
{
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[0].size(); j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector <int> vc2(m, 0);
	vector <vector <int>> vc(n, vc2);
	vector <vector <int>> visited(vc);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			int c; cin >> c;
			vc[i][j] = c;
			if (c == 1)
				maxCheese++;
		}
	}

	int prevCheeseCnt = maxCheese;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vc[i][j] == 0) {
				ZeroDotZero(vc, visited, i, j);
				TwoToZero(vc);
				init(visited);
				if (maxCheese != 0) {
					prevCheeseCnt = maxCheese;
				}
			}
		}
		if (maxCheese == 0)
			break;
	}

	cout << totalTime << '\n' << prevCheeseCnt;
	
}