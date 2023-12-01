#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;

	while (tc--) {
		int n; cin >> n;
		int arr[1001] = { 0, };
		bool visited[1001] = { 0, };
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			int c;  cin >> c;
			arr[i] = c;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				int next = arr[i];
				while (1) {
					// 방문한 노드라면 break
					if (visited[next]) {
						ans++;
						break;
					}
					else {
						visited[next] = true;
						next = arr[next];
					}
				}
			}
		}

		cout << ans << "\n";
	}
}