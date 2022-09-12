#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		string s, subs; cin >> s >> subs;

		int i = 0; int cnt = 0;
		int total = 0;
		while (i < s.length()) {
			int tmp = s.find(subs, i);
			if (tmp < 10001 && tmp >= 0) {
				cnt++;
				i = subs.length() + tmp;
				continue;
			}
			i++;
		}
		cout << s.length() - cnt * subs.length() + cnt << endl;
	}

}