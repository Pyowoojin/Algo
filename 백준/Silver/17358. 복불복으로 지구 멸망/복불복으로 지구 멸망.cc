#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 5 x 3 
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	ll start = n - 1;

	ll ans = 1;

	while (1) {
		if (start <= 1)
			break;

		ans *= start;
		ans = ans % 1000000007;
		start -= 2;
	}

	cout << ans;

}