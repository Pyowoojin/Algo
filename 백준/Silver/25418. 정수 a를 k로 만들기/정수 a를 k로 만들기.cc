#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	arr[n] = 0;

	fill(arr, arr + n, 0x7ffffff);

	for (int i = n + 1, j = n*2; i <= k; i++) {
		arr[i] = arr[i-1] + 1;

		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		if (i % 2 == 1)
			arr[i] = min(arr[i / 2] + 2, arr[i]);
	}
	
	/*for (int i = 0; i <= k; i++) {
		cout << i << " : " << arr[i] << endl;
	}*/

	cout << arr[k];

}