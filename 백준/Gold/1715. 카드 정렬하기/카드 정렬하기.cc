#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	priority_queue <int, vector <int>, greater<int>> pq;
	long long total = 0;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		pq.push(c);
	}
	int first = 0;
	int second = 0;

	while (pq.size() > 1) {
		first = pq.top(); pq.pop();
		total += first; 
		if (pq.size() > 0) {
			second = pq.top(); pq.pop();
			total += second;
		}
		pq.push(second + first);
	}

	if(pq.size() > 0)
		cout <<  total;
	else
		cout << pq.top() + total;

}