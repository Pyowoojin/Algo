#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string s; cin >> s;
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (i + 1 < s.length()) {
			if (s[i] == 'c') {
				if (s[i + 1] == '=' || s[i+1] == '-') {
					i++;
					cnt++;
				}
				else {
					cnt++;
				}
			}
			else if (s[i] == 'd') {
				if (s[i + 1] == '-') {
					i++;
					cnt++;
				}
				else if (i + 2 < s.length() && s[i + 1] == 'z' && s[i + 2] == '=') {
					i++; i++;
					cnt++;
				}
				else
					cnt++;

			}
			else if (s[i] == 'l') {
				if (s[i + 1] == 'j') {
					cnt++;
					i++;
				}
				else
					cnt++;
			}
			else if (s[i] == 'n')
			{
				if (s[i + 1] == 'j') {
					cnt++;
					i++;
				}
				else
					cnt++;
			}
			else if (s[i] == 's') {
				if (s[i + 1] == '=') {
					cnt++;
					i++;
				}
				else
					cnt++;
			}
			else if (s[i] == 'z') {
				if (s[i + 1] == '=') {
					cnt++;
					i++;
				}
				else
					cnt++;
			}
			else
				cnt++;
		}
		else
			cnt++;
	}

	cout << cnt;
}