#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int cnt = 0;
	int nex = n;
	bool flag;

	while (nex != 0) {
		flag = true;
		string s = to_string(nex);
		if (nex > 1) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '1') {
					s.erase(i, 1);
					nex = stoi(s);
					flag = false;
					cnt++;
					break;
				}
			}
		}

		if (flag == true) {
			nex = nex - 1;
			cnt++;
		}
	}

	cout << cnt;
}