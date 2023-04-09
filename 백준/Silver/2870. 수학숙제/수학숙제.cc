#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	/*else if (s1.length() == s2.length()) {
		return s1 > s2;
	}*/
	return s1 < s2;
}

string retZero(string s) {
	string retString = s;
	for (int i = 0, j = 0; i < s.length() - 1; i++,j++) {
		if (s[i] != '0') {
			break;
		}
		else {
			retString.erase(j, 1);
			j--;
		}
	}

	return retString;
}

int main() {
	int n; cin >> n;
	multiset <string> st;
	vector <string> vc;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		string tmp;
		for (int k = 0; k < s.length(); k++) {
			if (s[k] -'0' >= 0 && s[k] -'0' <= 9) {
				tmp += s[k];
			}
			else {
				if (tmp.length() > 0) {
					if (tmp[0] == '0') {
						tmp = retZero(tmp);
					}
					st.insert(tmp);
					vc.push_back(tmp);
				}
				tmp = "";
			}
		}
		if (tmp.length() > 0) {
			if (tmp[0] == '0') {
				tmp = retZero(tmp);
			}
			st.insert(tmp);
			vc.push_back(tmp);
		}
	}

	/*for (auto i : st)
		cout << i << '\n';*/
	sort(vc.begin(), vc.end(), comp);
	// cout << endl;

	for (auto i : vc)
		cout << i << endl;
}