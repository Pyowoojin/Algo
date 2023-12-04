#include <bits/stdc++.h>
using namespace std;

void prime(int k) {
	if (k == 1) {
		return;
	}
	else {
		for (int i = 2; i <= 10000000; i++) {
			if (k % i == 0) {
				cout << i << '\n';
				prime(k / i);
				break;
			}
		}
	}
}

int main() {
	int n; cin >> n;
	prime(n);
}