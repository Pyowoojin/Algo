#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc) {
		int n; cin >> n;

		int max = -1;

		while (1) {
			if (max <= n)
				max = n;

			if (n == 1)
				break;

			// n이 홀수라면 3을 곱한 뒤 1을 더함
			if (n % 2 == 1)
				n = n * 3 + 1;
			else if (n % 2 == 0)
				n = n / 2;
		}
		
		cout << max << '\n';

		tc--;
	}

}