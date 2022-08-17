#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;

	int* arr = new int[n + 1];
	fill(arr, arr + n + 1, 0);
	
	vector<int> v2;
	vector<vector<int>> v1(n+1, v2);

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int from, to; cin >> from >> to;
		v1[from].push_back(to);
		v1[to].push_back(from);
	}

	int cnt = 0;
	queue<int> q;
	q.push(1);
	arr[1] = 1;

	while (!q.empty()) {
		int tmp = q.front(); q.pop();
		for (int i = 0; i < v1[tmp].size(); i++) {
			if (arr[v1[tmp][i]] != 1) {
				q.push(v1[tmp][i]);
				arr[v1[tmp][i]] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;


}