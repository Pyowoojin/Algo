#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int* arr = new int[n + 1];
	fill(arr, arr + n + 1, 99999);
	arr[3] = 1, arr[5] = 1, arr[6] = 2, arr[8] = 2;

	for (int i = 7; i <= n; i++) {
		// arr[8] = arr[n-5], arr[n-3]
		if (arr[i - 5] != -1 && arr[i - 3] != -1) {
			//cout << " 5 : " << arr[i - 5] << " 3 : " << arr[i - 3] << endl;
			arr[i] = min(arr[i - 5], arr[i - 3]) + 1;
		}
	}

	if (arr[n] > 99998)
		cout << "-1";
	else
		cout << arr[n];


}