#include <bits/stdc++.h>
using namespace std;

int ans;
int ansCnt;

int graph(int nowX, vector <vector <int>>& vc, vector <int>& visited, int cnt) {
	if (visited[nowX])
		return cnt;
	else {
		visited[nowX] = true;
		return graph(vc[nowX][0], vc, visited, cnt + 1);
	}
}

void init(vector <int>& visited) {
	for (int i = 0; i < visited.size(); i++)
		visited[i] = 0;
}

int main() {
	int n; cin >> n;

	vector <vector <int>> vc(n);
	vector <int> visited(n, 0);
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		c--;
		vc[i].push_back(c);
	}

	for (int i = n - 1; i > -1; i--) {
		int k = graph(i, vc, visited, 0);
		if (ansCnt <= k) {
			ansCnt = k;
			ans = i;
		}
		init(visited);
	}

	cout << ans + 1;
}