#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n; cin >> n;

	while (n) {
		long long a, b; cin >> a >> b;
		long long maxN = max(a, b);
		long long minN = min(a, b);

		cout << a * b / gcd(maxN, minN) << endl;

		n--;
	}



}