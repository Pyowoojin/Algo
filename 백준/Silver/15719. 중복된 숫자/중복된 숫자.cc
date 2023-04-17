#include <bits/stdc++.h>
using namespace std;

bool arr[10000001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (!arr[c])
			arr[c] = true;
		else
			ans = c;
	}

	cout << ans;
}