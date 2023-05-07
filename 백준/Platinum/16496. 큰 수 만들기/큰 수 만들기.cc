#include <bits/stdc++.h>
using namespace std;

bool comp(string& s1, string& s2) {
	if (s1 + s2 > s2 + s1) {
		return true;
	}
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector <string> vc;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		vc.push_back(s);
	}

	sort(vc.begin(), vc.end(), comp);

	bool zeroAns = true;
	for (auto i : vc) {
		if (i != "0")
			zeroAns = false;
	}

	if (zeroAns)
		cout << "0";
	else {
		for (auto i : vc)
			cout << i;
	}
}
