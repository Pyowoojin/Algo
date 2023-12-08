#include <bits/stdc++.h>
using namespace std;

bool ans = true;

void IsPalin(string& s, int start, int end, int recurSize) {
	// 길이가 1까지 줄어들었다면 return
	if (recurSize == 1) {
		return;
	}

	// 이 문자열이 짝수라면
	if (int(s.length()) % 2 == 0) {
		for (int i = start, j = end - 1; i < recurSize / 2; i++, j--) {
			// 앞 뒤가 같지 않다면 팰린드롬이 아님
			if (s[i] != s[j]) {
				ans = false;
				return;
			}
		}
		// 문자열 반을 잘라서 재귀를 돌릴 것임
		// 왼쪽
		IsPalin(s, start, end / 2, recurSize / 2);
		// 오른쪽
		IsPalin(s, end / 2, end, recurSize / 2);
	}
	// 홀수일 경우
	else {
		for (int i = start, j = end - 1; i < recurSize / 2; i++, j--) {
			// 앞 뒤가 같지 않다면 팰린드롬이 아님
			if (s[i] != s[j]) {
				ans = false;
				return;
			}
		}
		// 문자열 반을 잘라서 재귀를 돌릴 것임
		IsPalin(s, start, end / 2, recurSize / 2);
		IsPalin(s, end / 2 + 1, end, recurSize / 2);
	}
}

int main() {
	string s; cin >> s;

	IsPalin(s, 0, s.length(), s.length());

	if (ans) {
		cout << "AKARAKA";
	}
	else {
		cout << "IPSELENTI";
	}
	
}