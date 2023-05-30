#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <int>>& vc, vector <int>& visited, int now) {
	visited[now] = 1;
	queue <int> q;
	q.push(now);
	int next = 0;
	int ans = 1;
	while (!q.empty()) {
		next = q.front(); q.pop();

		for (int i = 0; i < vc[next].size(); i++) {
			if (visited[vc[next][i]] == 0) {
				visited[vc[next][i]] = 1;
				q.push(vc[next][i]);
				ans++;
			}
		}
	}

	return ans;
}

void Clear(vector <int>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		visited[i] = 0;
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	int a, b; a = 0, b = 0;
	bool exit = false;
	while (n--) {
		char c; cin >> c;
		if (exit)
			continue;
		if (c == 'D') {
			a++;
		}
		else
			b++;

		if (abs(a - b) > 1) {
			exit = true;
		}
	}
	cout << a << ":" << b;
}