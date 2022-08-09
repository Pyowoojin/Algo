#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; getline(cin, s);
	string my; getline(cin, my);

	int i = 0;
	int ct = 0;
	while (i < s.length()) {
		if (s.find(my, i) != string::npos) {
			ct++;
			i = my.length() + s.find(my, i);
			continue;
		}
		i++;
	}

	cout << ct;

}