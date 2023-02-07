#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[10] = { 0, };

	int total = 0;
	for (int i = 0; i < 10; i++) {
		int c; cin >> c;
		total += c;
		arr[i] = total;
	}

	int maxN = 1001;
	int maxptr = -1;

	for (int i = 0; i < 10; i++) {
		if (maxN >= abs(100 - arr[i])) {
			if (maxptr < arr[i])
				maxptr = arr[i];
			maxN = abs(100 - arr[i]);

		}
	}

	cout << maxptr;

}