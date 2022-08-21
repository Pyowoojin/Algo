#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, first; cin >> n;
	cin >> first;
	int prev = first;
	int max = 0;
	int now = 0;
	for (int i = 1; i < n; i++) {
		int z; cin >> z;
		if (z - prev > 0) {
			now += z - prev;
			if (max < now)
				max = now;
		}
		else {
			now = 0;
		}
		prev = z;
	}

	cout << max;

}