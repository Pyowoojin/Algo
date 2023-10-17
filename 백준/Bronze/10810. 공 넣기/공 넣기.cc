#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		for (int i = x - 1; i < y; i++) {
			arr[i] = z;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}