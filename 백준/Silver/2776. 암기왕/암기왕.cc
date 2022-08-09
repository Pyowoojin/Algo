#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map <int, int> data;
	set <int> a2;
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m; cin >> n;
		cin.ignore();

		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			a2.insert(t);

		}
		cin >> m;

		for (int i = 0; i < m; i++) {
			int t; cin >> t;
			data.insert({ i, t });
		}


		for (auto iter = data.begin(); iter != data.end(); iter++) {
			if (a2.find(iter->second) != a2.end()) {
				iter->second = 1;
			}
			else {
				iter->second = 0;
			}
		}

		for (auto i = data.begin(); i != data.end(); i++) {
			cout << i->second << '\n';
		}
		data.clear();
		a2.clear();
	}
}