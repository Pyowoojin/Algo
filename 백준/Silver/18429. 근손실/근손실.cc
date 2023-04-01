#include <bits/stdc++.h>
using namespace std;

int ans;
int n, k;

vector <int> vc;
bool visited[8];

void dfs(int cnt, int total) {
	if (total < 500)
		return;

	if (cnt == vc.size()) {
		ans++;
		return;
	}

	for (int i = 0; i < vc.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(cnt + 1, total + vc[i] - k);
			visited[i] = false;
		}
	}
}

int main() {
	// 하루가 지날 때마다 중량이 k씩 감소한다.
	// 500 이상이 되도록 n일간의 운동 플랜을 세우고자 합니다.
	// N일 동안 N개의 운동 키트를 사용하는 경우의 수 중 3대 500을 유지하는 경우의 수는 몇가지나 될까요?
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	dfs(0, 500);

	cout << ans;
}