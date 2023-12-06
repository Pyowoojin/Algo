#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector <int> vc;
	vector <int> sum(n);
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
		if (i > 0) {
			sum[i] = sum[i - 1] + c;
		}
		else {
			sum[i] = c;
		}
	}

	int k; cin >> k;
	while (k--) {
		int start, end; cin >> start >> end;
		start--;
		end--;
		if (start == end) {
			cout << vc[start] << '\n';
		}
		else {
			if (start > 0) {
				cout << sum[end] - sum[start - 1] << '\n';
			}
			else {
				cout << sum[end] << '\n';
			}
		}
	}
}