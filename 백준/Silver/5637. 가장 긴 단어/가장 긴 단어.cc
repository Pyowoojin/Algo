#include <bits/stdc++.h>
using namespace std;

// 17 + 26 = 43
// 49 + 26 = 75

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string maxStr;

	while (1) {
		string s; cin >> s;
		// cout << "현재 문자열 : " << s << endl;
		if (s == "E-N-D")
			break;

		int curCount = 0;
		string tmp = "";

		for (int i = 0; i < s.length(); i++) {
			if (((s[i] - '0') > 48 && (s[i] - '0') < 76) || s[i] == '-') {
				curCount++;
				tmp += s[i];
			}
			else if (((s[i] - '0') > 16 && (s[i] - '0') < 44) || s[i] == '-') {
				curCount++;
				tmp += tolower(s[i]);
			}
		}

		if (curCount > maxStr.length()) {
			maxStr = tmp;
		}
	}

	cout << maxStr;


}