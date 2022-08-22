#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	int* arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i < n + 1; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] +1, arr[i]);
		if (i % 3 == 0)
			arr[i] = min(arr[i / 3] +1, arr[i]);

	}
	cout << arr[n];

}