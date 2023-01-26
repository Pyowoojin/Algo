#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s; cin >> s;


	for (int i = 0; i < s.length(); i++)
	{
		string tmp = to_string(int(s[i]));

		int total = 0;

		for (int j = 0; j < tmp.length(); j++) {
			total += tmp[j] - '0';
		}

		while (total--) {
			cout << s[i];
		}
		cout << '\n';
	}


}