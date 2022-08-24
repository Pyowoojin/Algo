#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int cnt = 0;

int prt(int ar[][501]) {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if (arr[i][j] == 1)
				cnt++;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int k = y1; k < y2; k++) {
			for (int l = x1; l < x2; l++) {
				arr[k][l] = 1;
			}

		}
	}

	cout << prt(arr);

}