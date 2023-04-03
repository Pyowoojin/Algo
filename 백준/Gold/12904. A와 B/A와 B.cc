#include <bits/stdc++.h>
using namespace std;

bool comp(string &s, string &t, bool dir) {
	if (dir) {
		if (s == t)
			return true;
	}
	else if (!dir) {
		if (s.length() != t.length()) {
			return false;
		}
		else {
			for (int i = t.length() - 1, j = 0; i > -1; i--, j++) {
				if (s[j] != t[i])
					return false;
			}
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s, t; cin >> s >> t;
	bool ans = false;

	// 1. A 삭제
	// 2. B 삭제 후 뒤집기
	bool dir = true;
	// true = 정방향, false = 역방향
	while (t.length() >= s.length()) {
		if (comp(s, t, dir)) {
			ans = true;
			break;
		}

		// 정방향일 때.
		if (dir) {
			if (t[t.length() - 1] == 'A') {
				t.pop_back();
			}
			else {
				t.pop_back();
				dir = !dir;
			}
		}
		// 역방향일 때
		else if (!dir) {
			if (t[0] == 'A') {
				t.erase(0, 1);
			}
			else {
				t.erase(0, 1);
				dir = !dir;
			}
		}
	}

	cout << ans;
}