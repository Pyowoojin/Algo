#include <bits/stdc++.h>
using namespace std;
bool visited[10002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector <int> vc(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> vc[i];
	}
	int a, b; cin >> a >> b;
	// 이동 횟수, 현재 위치
	queue <pair <int, int>> que;
	que.push({ 0, a});
	visited[a] = true;
	pair <int, int> temp;
	int ans = -1;

	while (!que.empty()) {
		temp = que.front();
		que.pop();
		if (temp.second == b) {
			ans = temp.first;
			break;
		}
		

		// 현재위치 + 배수
		for (int i = 1; temp.second + vc[temp.second] * i <= n; i++) {
			int next = temp.second + vc[temp.second] * i;
			if (!visited[next]) {
				que.push({ temp.first + 1, next });
				visited[next] = true;
			}
		}

		for (int i = 1; temp.second + (vc[temp.second] * i * -1) >= 1; i++) {
			int next = temp.second + (vc[temp.second] * i * -1);
			if (!visited[next]) {
				que.push({ temp.first + 1, next });
				visited[next] = true;
			}
		}
	}

	cout << ans;
}