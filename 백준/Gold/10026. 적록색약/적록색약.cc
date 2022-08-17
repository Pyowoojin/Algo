#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int colored = 0;
int noncolored = 0;

void init(vector<vector<int>>& visit) {
	for (int i = 0; i < visit.size(); i++) {
		for (int j = 0; j < visit[0].size(); j++) {
			visit[i][j] = 0;
		}
	}
}

void transNonC(vector<vector<int>>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			if (v1[i][j] == 0) {
				v1[i][j] = 1;
			}
		}
	}
}

void pr(const vector<vector<int>> &v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(const vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j, int toRecognize) {
	colored++;
	queue <pair<int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;
		for (int k = 0; k < 4; k++) {
			int dirx = x + dx[k];
			int diry = y + dy[k];
			if (dirx > -1 && diry > -1 && diry < v1.size() && dirx < v1.size()) {
				if (v1[dirx][diry] == toRecognize && visit[dirx][diry] == 0){
					visit[dirx][diry] = 1;
					q.push({ dirx,diry });
				}
			}
		}
	}
}

void nonCbfs(const vector<vector<int>>& v1, vector<vector<int>>& visit, int i, int j, int toRecognize) {
	noncolored++;
	queue <pair<int, int>> q;
	pair <int, int> tmp;
	q.push({ i,j });
	visit[i][j] = 1;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;
		for (int k = 0; k < 4; k++) {
			int dirx = x + dx[k];
			int diry = y + dy[k];
			if (dirx > -1 && diry > -1 && diry < v1.size() && dirx < v1.size()) {
				if (v1[dirx][diry] == toRecognize && visit[dirx][diry] == 0) {
					visit[dirx][diry] = 1;
					q.push({ dirx,diry });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;

	vector<int> v2(n, 0);
	vector<vector<int>> v1(n, v2);
	vector<vector<int>> visited(v1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			int tn = 0;
			if (c == 'R')
				tn = 1;
			else if (c == 'B')
				tn = 2;
			else if (c == 'G') 
				tn = 0;
			v1[i][j] = tn;
		}
	}

	// 기존 bfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				if (v1[i][j] == k && visited[i][j] == 0) {
					bfs(v1, visited, i, j, k);
				}
			}
		}
	}

	transNonC(v1);
	init(visited);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k < 3; k++) {
				if (v1[i][j] == k && visited[i][j] == 0) {
					nonCbfs(v1, visited, i, j, k);
				}
			}
		}
	}

	
	cout << colored << " " << noncolored;

}