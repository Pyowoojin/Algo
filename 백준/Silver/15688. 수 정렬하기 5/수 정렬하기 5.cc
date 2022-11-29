#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 중복의 경우
int positive_arr[1000001];
int negative_arr[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n; cin >> n;
	int minN = -1000000;
	int maxN = 1000000;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (c >= 0) {
			positive_arr[c]++;
		}
		else {
			negative_arr[1000000 + c]++;
		}

		if (maxN < c)
			maxN = c;
	}

	for (int i = 0; i < 1000000; i++) {
		if (negative_arr[i]) {
			for (int j = negative_arr[i]; j > 0; j--)
				cout << i-1000000 << '\n';
		}
	}
	for (int i = 0; i <= maxN; i++) {
		if (positive_arr[i]) {
			for (int j = positive_arr[i]; j > 0; j--)
				cout << i << '\n';
		}
	}
}