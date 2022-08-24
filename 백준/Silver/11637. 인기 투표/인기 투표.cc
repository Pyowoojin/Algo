#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	for (int i = 0; i < tc; i++) {
		vector <int> ls;
		int sum = 0;
		float calc = 0;
		int cand; cin >> cand;
		int max = 0;
		int maxcandi = 0;
		
		for (int j = 0; j < cand; j++) {
			int c; cin >> c;
			sum += c;
			ls.push_back(c);
			if (max < c) {
				max = c;
				maxcandi = j + 1;
			}
		}
		sort(ls.begin(), ls.end());
		calc = float(ls[cand-1]) / float(sum) * 100;
		// cout <<  endl << calc << endl;

		if (ls[cand-1] == ls[cand-2]) {
			cout << "no winner\n";
		}
		else if (calc > 50) {
			cout << "majority winner " << maxcandi << '\n';
		}
		else
			cout << "minority winner " << maxcandi << '\n';

		ls.clear();
	}
}