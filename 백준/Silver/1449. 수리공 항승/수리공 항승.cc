#include <bits/stdc++.h>
using namespace std;

bool arr[1001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l; cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr[c] = true;
	}

	int totalCnt = 0;

	for (int i = 0; i <= 1000; i++) {
		if (arr[i]) {
			totalCnt++;
			for (int j = 0; j < l; j++) {
				if (i + j <= 1000) {
					arr[i + j] = false;
				}
			}
		}
	}

	cout << totalCnt;
}
