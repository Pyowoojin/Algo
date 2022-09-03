#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

int arr[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 17과 42 -17하면댐ㅋ

	string s; cin >> s;

	string ans = "I'm Sorry Hansoo";

	for (int i = 0; i < s.length(); i++) {
		arr[(s[i] - '0' - 17)] += 1;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 == 1)
			cnt++;
	}

	// cout << char(17 + '0') << endl;

	if (cnt > 1)
		cout << ans;

	else {
		string pal = "";
		int odd = 999;
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 1)
				odd = i;
		}

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < arr[i] / 2; j++) {
				pal += char(i + 17 + '0');
			}
		}

		if (odd != 999)
			pal += char(odd + 17 + '0');

		for (int i = 25; i > -1; i--) {
			for (int j = 0; j < arr[i] / 2; j++) {
				pal += char(i + 17 + '0');
			}
		}

		cout << pal;
	}
}