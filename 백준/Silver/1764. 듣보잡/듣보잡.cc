#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	set <string> sett;
	set <string> ans;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		sett.insert(s);
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (sett.find(s) != sett.end())
			ans.insert(s);
	}

	cout << ans.size() << '\n';
	for (auto k = ans.begin(); k != ans.end(); k++)
		cout << *k << '\n';

}