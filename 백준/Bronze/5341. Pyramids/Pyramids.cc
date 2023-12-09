#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1000001] = { 0, };

int main() {
	int maxN = 0;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		if (n > maxN) {
			int maxValue = arr[maxN];
			for (int i = maxN + 1; i <= n; i++) {
				maxValue += i;
				arr[i] = maxValue;
			}
		}

		cout << arr[n] << '\n';

	}

}