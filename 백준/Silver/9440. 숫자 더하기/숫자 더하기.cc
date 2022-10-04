#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int n; cin >> n;
		if (n == 0)
			break;

		deque <int> vc;
		int zeroCnt = 0;

		for (int i = 0; i < n; i++) {
			int c; cin >> c;
			if (c == 0) {
				zeroCnt++;
				continue;
			}
			vc.push_back(c);
		}

		sort(vc.begin(), vc.end());

		string s1 = "", s2 = "";

		int i = 0;
		int zeroFlag = false;
		while (i < n) {
			if (i % 2 == 0) {
				if ((s1.length() != 0) && zeroCnt){
					s1 += "0";
					zeroCnt--;
					i++;
					continue;
				}

				s1 += char(vc.front() + '0');
				vc.pop_front();

			}
			else {
				if ((s2.length() != 0) && zeroCnt) {
					s2 += "0";
					zeroCnt--;
					i++;
					continue;
				}

				s2 += char(vc.front() + '0');
				vc.pop_front();

			}
			i++;
			// cout << "s1 : " << s1 << endl;
			// cout << "s2 : " << s2 << endl;
		}

		cout << stoi(s1) + stoi(s2) << endl;

	}


}