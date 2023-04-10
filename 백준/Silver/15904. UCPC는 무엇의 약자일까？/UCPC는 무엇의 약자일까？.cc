#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s;
	getline(cin, s);
	string t = "UCPC.";
	int strPTR = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[strPTR]) {
			strPTR++;
		}
	}

	// cout << strPTR << endl;

	if (strPTR >= 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}