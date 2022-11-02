#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << "";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool isTrue(string s) {
	int wcnt = 0, ocnt = 0, lcnt = 0, fcnt = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == 'w')
			wcnt++;
		if (s[i] == 'o')
			ocnt++;
		if (s[i] == 'l')
			lcnt++;
		if (s[i] == 'f')
			fcnt++;
	}
	if ((wcnt != ocnt) || (wcnt != lcnt) || (wcnt != fcnt) || (ocnt != lcnt) || (ocnt != fcnt) || (fcnt != ocnt) || (lcnt != fcnt)) {
		return 0;
	}
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool success = false;
	string s; cin >> s;
	
	int nowcnt = 0;
	int i = 0;

	success = isTrue(s);
	
	if (success) {
		while (i < s.length()) {
			int check = 0;
			success = false;
			if (s[i] == 'w') {
				i++; check++;
				while (s[i] == 'w' && i < s.length()) {
					i++; check++;
				}
				if (s[i] == 'o') {
					i++; check++;
					while (s[i] == 'o' && i < s.length()) {
						i++; check++;
					}
					if (s[i] == 'l') {
						while (s[i] == 'l' && i < s.length()) {
							i++; check++;
						}
						if (s[i] == 'f') {
							while (s[i] == 'f' && i < s.length()) {
								i++; check++;
							}
						}
						else
							break;
					}
					else
						break;
				}
				else
					break;
			}
			else
				break;
			string tmp = s.substr(nowcnt, check);
			// cout << tmp << endl;
			nowcnt = i;
			success = isTrue(tmp);
// 			i++;
		}
		cout << success;
	}
	else
		cout << '0';

}


