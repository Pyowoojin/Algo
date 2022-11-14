#include <bits/stdc++.h>
using namespace std;

bool isPalin(int n) {
	bool ans = true;
	stack <char> c;

	string s = to_string(n);

	// 짝수일 경우
	int i = 0;
	for (; i < s.size() / 2; i++) {
		c.push(s[i]);
	}

	// 홀수일 경우
	if (s.size() % 2 == 1)
		i++;

	for (; i < s.size(); i++) {
		char t = c.top(); c.pop();
		if (s[i] != t) {
			ans = false;
			break;
		}
	}
	return ans;
}

bool arr[10050002] = { false, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	arr[0] = arr[1] = true;

	m = min(m, 10050001);

	for (int i = 2; i <= sqrt(10050000); i++) {
		if (arr[i] == false) {
			for (int j = i + i; j <= 10050000; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (!arr[i]) {
			if (isPalin(i)) {
				cout << i << endl;
			}
		}
	}

	cout << "-1";

	return 0;
}