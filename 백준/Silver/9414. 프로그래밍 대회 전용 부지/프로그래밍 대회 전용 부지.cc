#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc; cin >> tc;
	while (tc--) {
		long long maxMoney = 5000000;
		long long total = 0;
		

		// 입력부
		long long c;
		vector <long long> vc;
		while (1) {
			cin >> c;
			if (c == 0)
				break;
			else
				vc.push_back(c);
		}

		sort(vc.begin(), vc.end(), greater<>());

		bool ans = true;
		for (int i = 0, powwow = 1; i < vc.size(); i++, powwow++) {
			if (powwow >= 23) {
				ans = false;
				break;
			}
			total += 2 * pow(vc[i], powwow);
		}
		if (!ans || total > maxMoney)
			cout << "Too expensive\n";
		else
			cout << total << '\n';
	}
}