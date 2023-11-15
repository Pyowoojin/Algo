#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> vc(n, 0);
	int ans[10];
	fill(ans, ans + 10, -1);

	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}

	for (int i = 0; i < n; i++) {
		int num = vc[i] + 1;
		int ptr = 0;
		while (num) {
			if (ans[ptr] == -1) {
				num--;
				if (num == 0) {
					ans[ptr] = i + 1;
				}
				ptr++;
			}
			else if (ans[ptr] < i + 1) {
				ptr++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (ans[i] != -1)
			cout << ans[i] << " ";
	}
}