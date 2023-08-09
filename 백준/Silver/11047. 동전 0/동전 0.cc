#include <iostream>

using namespace std;

int main() {
	int n, won, x;
	int count = 0;
	cin >> n >> won;

	int* coinarr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> x;
		coinarr[i] = x;
	}

	while (won) {
		for (int i = n-1; i >= 0; i--) {
			while (coinarr[i] <= won) {
				won = won - coinarr[i];
				count++;
			}
		}
	}

	cout << count;
}