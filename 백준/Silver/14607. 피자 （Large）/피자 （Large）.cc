#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n; cin >> n;
	n = n - 1;

	long long ans = (n * (n + 1)) / 2;
	cout << ans;
}