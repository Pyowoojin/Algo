#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector <string> vc;

	for (int i = 0; i < n; i++) {
		string c; cin >> c;
		vc.push_back(c);
	}

	vector <long long> s;

	for (int i = 0; i < vc.size(); i++) {
		string tmp;
		for (int k = vc[i].size() - 1; k >= 0; k--) {
			tmp += vc[i][k];
		}
		s.push_back(stoll(tmp));
	}

	sort(s.begin(), s.end());

	for (auto i : s)
		cout << i << '\n';
}