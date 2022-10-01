#include <bits/stdc++.h>
using namespace std;


// A = 17
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;


	while (tc) {

		int a, b; cin >> a >> b;

		queue <tuple <int, int, int>> tk;
		tuple <int, int, int> tmp;

		tk.push({ a, 0, b });

		while (!tk.empty()) {
			tmp = tk.front(); tk.pop();

			if (get<0>(tmp) == get<2>(tmp)) {
				cout << get<1>(tmp) << '\n';
				break;
			}

			int nX = get<0>(tmp) + 1;

			if (nX <= get<2>(tmp)) {
				tk.push({ nX, get<1>(tmp) + 1, get<2>(tmp) });
			}

			int trX = get<0>(tmp) * 2;

			if (trX <= get<2>(tmp) + 3) {
				tk.push({ trX, get<1>(tmp) + 1, get<2>(tmp) + 3 });
			}

		}
		tc--;
	}

}