#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	while (tc) {
		int a, b, c; cin >> a >> b >> c;
		int d = c % a, e = c / a;
		if (d > 0)
			e++;
		else
			d = a;

		cout << d * 100 + e << endl;

		tc--;
	}
}