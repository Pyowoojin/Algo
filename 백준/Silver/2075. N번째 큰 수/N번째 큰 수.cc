#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	priority_queue <int> pq;

	for (int i = 0; i < n * n; i++) {
		int k; cin >> k;
		k = -k;
		if (pq.size() == n) {
			if (pq.top() > k) {
				pq.pop();
				pq.push(k);
			}
		}
		else
			pq.push(k);
	}
	cout << -pq.top();
}