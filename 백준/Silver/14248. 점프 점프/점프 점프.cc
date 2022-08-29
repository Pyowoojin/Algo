#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	
	int* arr = new int[n];
	int* visit = new int[n];
	fill(visit, visit + n, 0);

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr[i] = c;
	}

	int start; cin >> start;
	queue <int> q;
	q.push(start-1);
	visit[start-1] = 1;
	int nowIndex = 0;

	while (!q.empty()) {
		nowIndex = q.front(); q.pop();
		
		int nR = nowIndex + arr[nowIndex];
		int nL = nowIndex - arr[nowIndex];

		if (nR < n) {
			if (visit[nR] != 1) {
				visit[nR] = 1;
				q.push(nR);
			}
		}

		if (nL > -1) {
			if (visit[nL] != 1) {
				visit[nL] = 1;
				q.push(nL);
			}
		}
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (visit[i] == 1) {
			ans++;
		}
	}

	cout << ans;


}