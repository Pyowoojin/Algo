#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool isPalin(string s) {
	int len = s.length();
	stack <char> stk;

	// 짝수일 경우 팰린드롬 판별
	if (len % 2 == 0) {
		for (int i = 0; i < len / 2; i++) {
			stk.push(s[i]);
		}

		for (int i = len / 2; i < len; i++) {
			char comp = stk.top(); stk.pop();
			if (comp != s[i])
				return 0;
		}

		return 1;
	}

	else if (len % 2 == 1) {
		for (int i = 0; i < len / 2; i++) {
			stk.push(s[i]);
		}

		for (int i = len / 2 + 1; i < len; i++) {
			char comp = stk.top(); stk.pop();
			if (comp != s[i])
				return 0;
		}

		return 1;
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;

	bool isPalindrome = false;

	isPalindrome = isPalin(s);

	if (isPalindrome) {
		// 팰린드롬이면 맨 뒤 문자 하나 제거하고 다시 비교
		s.pop_back();
		// 또다시 팰린드롬이라면 무적의 문자열임
		if (isPalin(s)) {
			cout << "-1";
		}
		else
			cout << s.length();
	}
	else {
		cout << s.length();
	}

}