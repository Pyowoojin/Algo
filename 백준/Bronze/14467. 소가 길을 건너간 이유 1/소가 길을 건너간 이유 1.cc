#include <bits/stdc++.h>
using namespace std;

int arr[11];
bool visited[11];
bool init[11];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int cow, loc; cin >> cow >> loc;

		// 맨 처음이라면
		if (!init[cow]) {
			init[cow] = true;
			visited[cow] = loc;
		}
		else {
			// 처음 방문이 아닌데 위치가 달라졌다면 arr++
			if (visited[cow] != loc) {
				arr[cow]++;
				visited[cow] = loc;
			}
		}
	}
	int maxN = 0;

	for (int i = 0; i < 11; i++) {
		maxN += arr[i];
	}
	cout << maxN;


}