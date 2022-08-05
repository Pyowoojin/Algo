#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	// S = A[0] X B[0] + ... + A[N-1] X B[N-1]
	vector <int> a, b;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + (a[i] * b[i]);
	}

	cout << sum << endl;

}