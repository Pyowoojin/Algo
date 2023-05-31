#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s1, oper, s2; cin >> s1 >> oper >> s2;
	string LongString, ShortString;
	if (s1.length() < s2.length()) {
		LongString = s2;
		ShortString = s1;
	}
	else {
		LongString = s1;
		ShortString = s2;
	}

	if (oper == "+") {
		LongString[LongString.length() - ShortString.length()] = (LongString[LongString.length() - ShortString.length()] - '0' + ShortString[0] - '0') + '0';
	}
	else if (oper == "*") {
		for (int i = 0; i < ShortString.length() - 1; i++) {
			LongString.push_back('0');
		}
	}

	cout << LongString;
}