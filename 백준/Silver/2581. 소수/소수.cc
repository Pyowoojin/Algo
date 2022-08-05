#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k; cin >> k >> n;
	int* arr = new int[n + 1];
	fill(arr, arr + n + 1, 1);
	arr[0] = 0; arr[1] = 0;

	for (int i = 2; i <= n; i += 2)
		arr[i] = 0;

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;
	}
	arr[2] = 1;

	int sum = 0;
	int min = 10001;
	for (int i = k; i <= n; i++) {
		if (arr[i] == 1) {
			if (min > i)
				min = i;
			sum += i;
		}
	}

	if (min == 10001)
		cout << "-1";
	else cout << sum << '\n' << min;
}