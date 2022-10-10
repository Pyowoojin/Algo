#include <bits/stdc++.h>
using namespace std;

void init(bool arr[]) {
	for (int i = 0; i < 26; i ++)
		arr[i] = 0;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int alpha[26];
	bool alphaVisit[26] = { 0, };
	int total = 0;

	for (int i = 65, j = 0; i < 91; i++, j++) {
		alpha[j] = i;
		total += i;
	}

	int tc; cin >> tc;

	while (tc) {
		int cnt = 0;
		int to = total;
		string s; cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (!alphaVisit[s[i] - '0' - 17]) {
				alphaVisit[s[i] - '0' - 17] = 1;
				cnt += alpha[s[i] - '0' - 17];
			}
		}

		to -= cnt;

		cout << to << endl;
		init(alphaVisit);

		tc--;

	}
}