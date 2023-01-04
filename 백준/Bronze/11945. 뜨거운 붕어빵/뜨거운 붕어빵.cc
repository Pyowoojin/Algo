#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector <char> vc2(m, 0);
	vector <vector <char>> vc(n, vc2);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			vc[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = m-1; j > -1; j--) {
			cout << vc[i][j];
		}
		cout << '\n';
	}

}