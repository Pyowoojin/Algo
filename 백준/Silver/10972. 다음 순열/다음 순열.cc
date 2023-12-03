#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr.push_back(c);
	}
	if (next_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
}