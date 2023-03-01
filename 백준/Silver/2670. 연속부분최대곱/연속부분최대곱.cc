#include <bits/stdc++.h>
using namespace std;

double dp[3][10];

int main() {
	cout << fixed;
	cout.precision(3);

	int n; cin >> n;
	
	double* arr = new double[n];
	double* dp = new double[n];

	for (int i = 0; i < n; i++) {
		double c; cin >> c;
		arr[i] = c;
		dp[i] = c;
	}

	double maxN = -1;

	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i - 1] * arr[i], arr[i]);
		maxN = max(dp[i], maxN);
	}

	cout << maxN;
}