#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	long long arr[118] = { 0, };
	arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2;
	for (int i = 5; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 3];
	}
	cout << arr[n];

}