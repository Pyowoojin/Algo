#include <bits/stdc++.h>
using namespace std;

int charToInt(char c) {
	map<char, int> mp;

	mp['-'] = 0;
	mp['\\'] = 1;
	mp['('] = 2;
	mp['@'] = 3;
	mp['?'] = 4;
	mp['>'] = 5;
	mp['&'] = 6;
	mp['%'] = 7;
	mp['/'] = -1;

	return mp[c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	while (1) {
		string s; cin >> s;
		int total = 0;
		int first = s.length() - 1;
		if (s == "#")
			break;

		for (int i = 0; i < s.length(); i++) {
			total += charToInt(s[i]) * pow(8, first);
			first--;
		}

		cout << total << endl;
	}
}