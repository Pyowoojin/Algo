#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <T> &v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		dq.push_back(c);
	}

	sort(dq.begin(), dq.end());

	int sum = 0;
	if (dq.size() % 2 == 0) {
		int a = dq.front(); dq.pop_front();
		int b = dq.front(); dq.pop_front();
		sum = a * b;
		b = a + b;
		while (!dq.empty()) {
			a = dq.front(); dq.pop_front();
			sum += a * b;
			b = a + b;
		}
		cout << sum;
	}
	else {
		int a = dq.back(); dq.pop_back();
		int b = dq.front(); dq.pop_front();
		sum = a * b;
		b = a + b;

		while (!dq.empty()) {
			a = dq.front(); dq.pop_front();
			sum += a * b;
			b = a + b;
		}
		cout << sum;
	}
}