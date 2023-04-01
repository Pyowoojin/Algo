#include <bits/stdc++.h>
using namespace std;

int arr[4] = { 1,5,10,50 };
bool visited[1001];
int ans;

void dfs(int maxN, int nowN, int index, int total) {
	if (maxN == nowN) {
		if (!visited[total]) {
			visited[total] = true;
			ans++;
		}
		return;
	}

	for (int i = index; i < 4; i++) {
		dfs(maxN, nowN + 1, i, total + arr[i]);
	}
}

int main() {
	int n; cin >> n;

	dfs(n, 0, 0, 0);

	cout << ans;
}