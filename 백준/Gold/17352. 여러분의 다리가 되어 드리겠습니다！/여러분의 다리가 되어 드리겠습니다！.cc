#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int bfs(vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j) {
	int nowCnt = 1;
	queue<pair<int, int>> q;
	pair<int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first;
		int y = tmp.second;
		for (int k = 0; k < 4; k++) {
			int nX = dx[k] + x;
			int nY = dy[k] + y;

			if (nX > -1 && nY > -1 && nX < v1.size() && nY < v1[0].size()) {
				if (visit[nX][nY] != 1 && v1[nX][nY] == 1) {
					nowCnt++;
					q.push({ nX, nY });
					visit[nX][nY] = 1;
				}
			}
		}
	}

	return nowCnt;
}

int start = 0, end = 0;

void dfs(vector<int> graph[], int start, bool visit[]) {
	visit[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (visit[next] == 0) {
			dfs(graph, next, visit);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int island; cin >> island;

	vector <int>* graph = new vector<int>[island + 1];

	bool* visit = new bool[island + 1];

	fill(visit, visit + island + 1, 0);

	for (int i = 0; i < island - 2; i++) {
		int from, to; cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<int> ans;



	for (int i = 1; i < island + 1; i++) {
		if (visit[i] == 0) {
			ans.push_back(i);
			dfs(graph, i, visit);
		}
	}

	for (auto z : ans)
		cout << z << " ";


}