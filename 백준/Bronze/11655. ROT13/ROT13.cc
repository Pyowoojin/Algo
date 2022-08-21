#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int upchar[100] = { 0, };

	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i]))
			upchar[i] = 1;
		s[i] = tolower(s[i]);
		if (s[i] > 96 && s[i] < 123) {
			if (s[i] + 13 > 122) {
				s[i] = s[i] + 13 - 122 + 96;
			}
			else {
				s[i] = s[i] + 13;
			}
		}
		if (s[i] == ' ') {
			continue;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (upchar[i] == 1) {
			cout << char(s[i] - 32);
		}
		else
			cout << s[i];
	}

}