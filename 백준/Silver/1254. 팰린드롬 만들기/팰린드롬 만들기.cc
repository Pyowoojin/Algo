#include <bits/stdc++.h>
using namespace std;

bool IsPalin(string &s) {
	bool ans = true;
	for (int i = 0, j = s.length()-1; i < s.length(); i++, j--) {
		if (s[i] != s[j]) {
			ans = false;
		}
	}
	return ans;
}

string StringDouble(string& s) {
	string retStr = s;

	for (int i = s.length() - 1; i > -1; i--) {
		retStr += s[i];
	}

	return retStr;
}

int main() {
	string s; cin >> s;
	int ans = s.length();

	// 맨 처음부터 회문일 경우 기존 문자열의 크기를 출력
	if (IsPalin(s)){
		cout << ans;
	}
	// 팰린드롬을 만들어야 할 경우
	else {
		// 2배를 해주고, 추가된 문자열의 맨 앞부터 빼주며 검사함
		// 만약, 원래 문자열의 크기까지 회문이 나오지 않을 경우 X2 한 것이 정답이 됨.
		string newStr = StringDouble(s);
		
		int ptr = s.length();
		ans = s.length() * 2;
		while (newStr.length() > s.length()) {
			newStr.erase(ptr, 1);
			if (IsPalin(newStr)) {
				ans = newStr.length();
			}
		}

		cout << ans;
	}
}