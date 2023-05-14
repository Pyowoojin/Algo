#include <bits/stdc++.h>
using namespace std;

unsigned long long arr[46];

int main() {
	int n; cin >> n;
	
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 3;

	if (n < 5) {
		cout << arr[n];
	}
	else {
		for (int i = 5; i <= n; i ++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[n];
	}
}