#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue <int, vector<int>, greater<int>> pq;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int command; cin >> command;
		if (command == 0) {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			cout << pq.top() << '\n'; pq.pop();
		}
		else {
			pq.push(command);
		}
	}

}