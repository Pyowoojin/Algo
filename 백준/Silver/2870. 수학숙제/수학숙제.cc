#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
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

// out of range가 났던 이유 : N이 100자까지 입력 될 수 있음
// 1. 00070같은 앞의 불필요한 0을 제거해야함
// 2. 숫자로 판단되는 문자열을 vector에 넣고 정렬을 수행해야 함

int main() {
	int n; cin >> n;
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
					vc.push_back(tmp);
				}
				tmp = "";
			}
		}
		if (tmp.length() > 0) {
			if (tmp[0] == '0') {
				tmp = retZero(tmp);
			}
			vc.push_back(tmp);
		}
	}

	sort(vc.begin(), vc.end(), comp);

	for (auto i : vc)
		cout << i << '\n';
}