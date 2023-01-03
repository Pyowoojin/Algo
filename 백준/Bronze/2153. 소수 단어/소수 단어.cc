#include <bits/stdc++.h>
using namespace std;

bool arr[11000];

void PrimNum() {
	arr[0] = true;
	for (int i = 2; i * i <= 11000; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= 11000; j += i)
				arr[j] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int total = 0;

	// char a = 'a'; // 49 ~ 74
	// char bigA = 'A'; // 17 ~ 42

	PrimNum();

	for (int i = 0; i < s.length(); i++) {
		// 소문자인 경우. 1 ~ 26로 세팅
		if (s[i] - '0' >= 49 && s[i] - '0' <= 74) {
			total += (s[i] - '0' - 48);
		}
		// 대문자인 경우. 27 ~ 52로 세팅
		else if (s[i] - '0' >= 17 && s[i] -'0' <= 42) {
			total += (s[i] - '0' + 10);
		}
	}

	/*for (int i = 0; i < 1100; i++) {
		if (!arr[i])
			cout << i << endl;
	}*/

	if (!arr[total]) {
		cout << "It is a prime word.";
	}
	else
		cout << "It is not a prime word.";

}