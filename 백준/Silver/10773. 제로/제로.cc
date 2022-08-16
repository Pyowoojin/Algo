#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque <int> dq;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int z; cin >> z;
		if (z == 0) {
			dq.pop_back();
		}
		else {
			dq.push_back(z);
		}
	}

	cout << accumulate(dq.begin(), dq.end(), 0);

}