#include <bits/stdc++.h>
using namespace std;

int strS(char c, int i) {
	return (c - '0' - 17)* pow(26, i);
}

// A = 17
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	while (n) {
		string s; cin >> s;

		int strSum = 0;

		for (int i = 2, j = 0; i >= 0; i--, j++)
			strSum += strS(s[j], i);

		string tmp = "";
		for (int i = 4; i < s.length(); i++) {
			tmp += s[i];
		}

		int in = stoi(tmp);

		in = abs(strSum - in);

		if (in <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
		n--;
	}


}