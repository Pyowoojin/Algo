#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, s; cin >> n >> s;

	int ans = 1e9;
	int sum = 0;
	int start = 0;

	vector <int> vc(n);


	for (int i = 0; i < n; i++) {
		int c; cin >> c; vc[i] = c;
		sum += c;
		// 합친 것이 s보다 커진다면
		if (sum >= s) {
			while (sum - vc[start] >= s) {
				sum -= vc[start];
				start++;
			}
			ans = min(ans, i - start + 1);
		}

	}
	if (ans == 1e9)
		cout << '0';
	else
		cout << ans;
	
}