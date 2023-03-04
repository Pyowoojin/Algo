#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k; cin >> n >> k;
	vector <int> vc;
	
	string s;
	cin >> s;

	int i = 0;
	string tmp;
	while (i < s.length()) {
		if (s[i] == ',') {
			vc.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += s[i];
		}
		i++;
	}
	vc.push_back(stoi(tmp));

	while (k--) {
		for (int i = 0; i < vc.size() - 1; i++) {
			vc[i] = vc[i + 1] - vc[i];
		}
		vc.pop_back();
	}

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i];
		if (i + 1 != vc.size())
			cout << ",";
	}

}