#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	deque <char> dq;
	
	stack <int> lastOrder;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int order; cin >> order;

		if (order == 1) {
			lastOrder.push(1);
			char c; cin >> c;
			dq.push_back(c);
		}
		else if (order == 2) {
			lastOrder.push(0);
			char c; cin >> c;
			dq.push_front(c);
		}
		else {
			if (!lastOrder.empty()) {
				int dir = lastOrder.top();
				lastOrder.pop();

				// 1인 경우 뒤에서 빼기
				if (dir) {
					dq.pop_back();
				}
				// 0인 경우 앞에서 빼기
				else {
					dq.pop_front();
				}
			}
		}
		
	}

	if (dq.size() == 0) {
		cout << "0";
	}
	else {
		for (auto i = dq.begin(); i != dq.end(); i++)
			cout << *i;
	}
}